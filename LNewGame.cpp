#include "LNewGame.h"

#include "LConst.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>

LNewGame::LNewGame(QWidget* widget)
	:
	QDialog(widget, Qt::WindowTitleHint | Qt::WindowSystemMenuHint),
	biRadio(new QRadioButton("Two players")),
	botRadio(new QRadioButton("Versus Bot")),
	netRadio(new QRadioButton("Versus Internet-players")),
	name1(new QLabel("Name 1:")),
	name2(new QLabel("Name 2:")),
	name1Edit(new QLineEdit),
	name2Edit(new QLineEdit),
	whiteRadio(new QRadioButton("White")),
	blackRadio(new QRadioButton("Black")),
	anyRadio(new QRadioButton("Any"))
{
	QVBoxLayout* mainLayout = new QVBoxLayout;

	QGroupBox* game = new QGroupBox("Game's Type");
	QVBoxLayout* hLayoutGameType = new QVBoxLayout;

	QHBoxLayout* hLayoutName1 = new QHBoxLayout;
	QHBoxLayout* hLayoutName2 = new QHBoxLayout;

	QGroupBox* color = new QGroupBox("Color");
	QHBoxLayout* hLayoutColor = new QHBoxLayout;

	QHBoxLayout* hLayoutButton = new QHBoxLayout;
	QPushButton* buttonOk = new QPushButton("Ok");
	QPushButton* buttonCancel = new QPushButton("Cancel");

	mainLayout->addWidget(game);
	game->setLayout(hLayoutGameType);
	hLayoutGameType->addWidget(this->biRadio);
	hLayoutGameType->addWidget(this->botRadio);
	hLayoutGameType->addWidget(this->netRadio);

	mainLayout->addLayout(hLayoutName1);
	hLayoutName1->addWidget(this->name1);
	hLayoutName1->addWidget(this->name1Edit);

	mainLayout->addLayout(hLayoutName2);
	hLayoutName2->addWidget(this->name2);
	hLayoutName2->addWidget(this->name2Edit);

	mainLayout->addWidget(color);
	color->setLayout(hLayoutColor);
	hLayoutColor->addWidget(this->whiteRadio);
	hLayoutColor->addWidget(this->blackRadio);
	hLayoutColor->addWidget(this->anyRadio);

	mainLayout->addLayout(hLayoutButton);
	hLayoutButton->addWidget(buttonOk);
	hLayoutButton->addWidget(buttonCancel);

	connect(this->biRadio, SIGNAL(clicked()), SLOT(slotCheckBi()));
	connect(this->botRadio, SIGNAL(clicked()), SLOT(slotCheckBotNet()));
	connect(this->netRadio, SIGNAL(clicked()), SLOT(slotCheckBotNet()));

	connect(buttonOk, SIGNAL(clicked()), SLOT(accept()));
	connect(buttonCancel, SIGNAL(clicked()), SLOT(reject()));

	this->botRadio->setChecked(true);
	this->anyRadio->setChecked(true);

	this->setWindowTitle("New Game");
	this->setWindowIcon(QIcon());
	this->resize(300, 270);
	this->slotCheckBotNet();
	this->setLayout(mainLayout);
	this->setModal(true);
	this->show();
}

void LNewGame::slotCheckBi()
{
	this->name1Edit->setVisible(true);
	this->name2Edit->setVisible(true);
	this->name1->setVisible(true);
	this->name2->setVisible(true);
}

void LNewGame::slotCheckBotNet()
{
	this->name1Edit->setVisible(false);
	this->name2Edit->setVisible(false);
	this->name1->setVisible(false);
	this->name2->setVisible(false);
}

int LNewGame::getGameType() const
{
	if (this->biRadio->isChecked())
	{
		return LConst::L_TYPE_BI;
	}
	else if (this->botRadio->isChecked())
	{
		return LConst::L_TYPE_BOT;
	}
	else
	{
		return LConst::L_TYPE_NET;
	}
}

int LNewGame::getColor() const
{
	if (this->whiteRadio->isChecked())
	{
		return LConst::L_COLOR_WHITE;
	}
	else if (this->blackRadio->isChecked())
	{
		return LConst::L_COLOR_BLACK;
	}
	else
	{
		return LConst::L_COLOR_ANY;
	}
}

QString LNewGame::getName1() const
{
	return this->name1Edit->text();
}

QString LNewGame::getName2() const
{
	return this->name2Edit->text();
}