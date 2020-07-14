#include "LPlayer.h"

#include "LFigure.h"

LPlayer::LPlayer(int c, QString n)
	:
	color(c),
	name(n)
{

}

LPlayer::LPlayer(const LPlayer& player)
	:
	color(player.color),
	name(player.name)
{

}

LPlayer* LPlayer::getClone()
{
	return new LPlayer(*this);
}

int LPlayer::getColor() const
{
	return this->color;
}

QString LPlayer::getName() const
{
	return this->name;
}

int LPlayer::getFigureCount()
{
	return this->figures.size();
}

LFigure* LPlayer::operator [] (int index) const
{
	return this->figures[index];
}

void LPlayer::setName(QString name)
{
	this->name = name;
}

void LPlayer::addFigure(LFigure* figure)
{
	this->figures.push_back(figure);
}
