#pragma once

#include <QString>
#include <QVector>
#include <QTextStream>

class QJsonObject;

class LFigure;

class LPlayer
{
private:
	LPlayer* original;

	int color;
	QString name;
	QVector<LFigure*> figures;

public:
	LPlayer(int color, QString name = "");
	LPlayer(const LPlayer& player);

	static LPlayer* playerFromJson(QJsonObject* document);
	static QString toJsonClientString(QString name);
	static QString toJsonServerString(QString name);

	LPlayer* getOriginal() const;
	LPlayer* getClone() const;
	int getColor() const;
	QString getName() const;
	QString getText() const;

	int getFigureCount() const;
	LFigure* operator [] (int index) const;

	void setName(QString name);

	void addFigure(LFigure* figure);

	friend QTextStream& operator >> (QTextStream& out, LPlayer& player);
	friend QTextStream& operator << (QTextStream& in, const LPlayer& player);

};
