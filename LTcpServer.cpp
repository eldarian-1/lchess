#include "LTcpServer.h"

#include "LConst.h"
#include "LPath.h"
#include "LPlayer.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

struct LTcpServerPrivate
{
	bool isConnected;
	quint16 size;
	QTcpServer* server;
	QTcpSocket* client;

	LTcpServerPrivate(LTcpServer* server, int port);
	~LTcpServerPrivate();
};

LTcpServerPrivate::LTcpServerPrivate(LTcpServer* server, int port)
	:
	isConnected(false),
	size(0),
	server(new QTcpServer(server)),
	client(nullptr)
{
	
}

LTcpServerPrivate::~LTcpServerPrivate()
{
	delete client;
	delete server;
}

LTcpServer::LTcpServer(int port)
	:
	LClient(),
	m(new LTcpServerPrivate(this, port))
{
	m->server->listen(QHostAddress::Any, port);
}

LTcpServer::~LTcpServer()
{
	delete m;
}

void LTcpServer::newGame(QString name)
{
	sendToClient(LPlayer::toJsonServerString(name));
}

void LTcpServer::sendPath(LPath* path)
{
	sendToClient(path->toJsonString());
}

void LTcpServer::getPath()
{

}

void LTcpServer::sendToClient(const QString& string)
{
	QByteArray arrBlock;

	QDataStream out(&arrBlock, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_14);
	out << quint16(0) << string;

	out.device()->seek(0);
	out << quint16(arrBlock.size() - sizeof(quint16));

	m->client->write(arrBlock);
}

void LTcpServer::slotNewConnection()
{
	if (!m->client && !m->isConnected)
	{
		m->isConnected = true;
		m->client = m->server->nextPendingConnection();
		connect(m->client, SIGNAL(disconnected()), m->client, SLOT(deleteLater()));
		connect(m->client, SIGNAL(disconnected()), SLOT(slotDeleteSocket()));
		connect(m->client, SIGNAL(readyRead()), SLOT(slotReadClient()));
	}
	else
	{
		m->server->nextPendingConnection()->abort();
	}
}

void LTcpServer::slotDeleteSocket()
{
	delete m->client;
	m->client = nullptr;
	emit signalStatusChange(L_GAME_PAUSE);
}

void LTcpServer::slotReadClient()
{
	QDataStream in(m->client);
	in.setVersion(QDataStream::Qt_5_14);

	while (true)
	{
		if (!m->size)
		{
			if (m->client->bytesAvailable() < sizeof(quint16))
			{
				break;
			}
			in >> m->size;
		}

		if (m->client->bytesAvailable() < m->size)
		{
			break;
		}

		QByteArray query;
		in >> query;
		m->size = 0;
		
		QJsonObject object = QJsonDocument::fromJson(query).object();
		if (m->isConnected)
		{
			LPath* path = LPath::pathFromJson(&object);
			emit signalGetPath(path);
		}
		else
		{
			LPlayer* player = LPlayer::playerFromJson(&object);
			m->isConnected = true;
			emit signalNewGame(player);
		}
	}
}
