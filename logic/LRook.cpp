#include "LRook.h"

#include "LDesk.h"
#include "LGame.h"
#include "LConst.h"

#include "LPath.h"
#include "LSquare.h"

LRook::LRook(int color)
	:
	LFigure(color),
	_isWalked(false)
{
	
}

void LRook::draw(LSquare* position, bool reverse)
{
	LDesk::getInstance()->drawRook(this->color, position, reverse);
}

int LRook::isPossiblePath(LPath* path)
{
	LGame* game = LGame::getInstance();
	int flag = L_PATH_TRUE;

	int xC = path->getFrom()->getHorizontal();
	int yC = path->getFrom()->getVertical();
	int xT = path->getTo()->getHorizontal();
	int yT = path->getTo()->getVertical();

	LRook* target = (LRook*)game->getFigure(yT, xT);

	flag = (((target == nullptr) || (target->color != this->color)) && ((xC == xT) || (yC == yT)))
		? (L_PATH_TRUE) : (L_PATH_FALSE);

	if (xC < xT)
	{
		for (int i = xC + 1; i < xT && flag; i++)
			flag = (game->getFigure(yC, i) == nullptr) ? (L_PATH_TRUE) : (L_PATH_FALSE);
	}
	else if (xC > xT)
	{
		for (int i = xT + 1; i < xC && flag; i++)
			flag = (game->getFigure(yC, i) == nullptr) ? (L_PATH_TRUE) : (L_PATH_FALSE);
	}
	else if (yC < yT)
	{
		for (int i = yC + 1; i < yT && flag; i++)
			flag = (game->getFigure(i, xC) == nullptr) ? (L_PATH_TRUE) : (L_PATH_FALSE);
	}
	else if (yC > yT)
	{
		for (int i = yT + 1; i < yC && flag; i++)
			flag = (game->getFigure(i, xC) == nullptr) ? (L_PATH_TRUE) : (L_PATH_FALSE);
	}

	if (!(flag == L_PATH_FALSE) && !this->_isWalked)
		this->_isWalked = true;

	if (game->getIsCheck() & this->color)
	{
		if ((flag & L_PATH_TRUE) && (game->isCheck(this->getColor(), yT, xT, yC, xC) & L_PATH_CHECK))
			flag = L_PATH_FALSE;
	}
	else
	{
		if ((flag & L_PATH_TRUE) && (game->isCheck(this->getColor(), yC, xC) & L_PATH_CHECK))
			flag = L_PATH_FALSE;
	}

	return flag;
}

int LRook::getType() const
{
	return L_FIGURE_ROOK;
}

int LRook::getValue() const
{
	return L_VALUE_ROOK;
}

QString LRook::getName() const
{
	return "Rook";
}

bool LRook::isWalked() const
{
	return this->_isWalked;
}

void LRook::setWalked(bool isWalked)
{
	this->_isWalked = isWalked;
}
