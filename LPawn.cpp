#include "LPawn.h"

#include "LDesk.h"
#include "LGame.h"
#include "LConst.h"

LPawn::LPawn(int color)
	: LFigure(color)
{
	this->type = L_FIGURE_PAWN;
}

void LPawn::draw(LSquare* position, bool reverse)
{
	LDesk::getInstance()->drawPawn(this->color, position, reverse);
}

int LPawn::isPossiblePosition(LSquare* oldPosition, LSquare* newPosition)
{
	LGame* game = LGame::getInstance();
	int flag = L_PATH_TRUE;

	int xC = oldPosition->getHorizontal();
	int yC = oldPosition->getVertical();
	int xT = newPosition->getHorizontal();
	int yT = newPosition->getVertical();

	LPawn* target = (LPawn*)game->getFigure(yT, xT);

	if (this->color == L_COLOR_WHITE)
	{
		if ((xC == xT) && (yC == 6) && (yT == 5 || yT == 4))
		{
			flag = (((yT == 5) && (!target)) || ((yT == 4) && (!target) && !(LPawn*)game->getFigure(5, xT)))
				? (L_PATH_TRUE) : (L_PATH_FALSE);
		}
		else if (target && (target->color != this->color) && ((abs(xC - xT) == 1) && ((yC - yT) == 1)))
		{
			flag = L_PATH_TRUE;
		}
		else if (!target && (xC == xT) && (yC - yT == 1))
		{
			flag = L_PATH_TRUE;
		}
		else
		{
			flag = L_PATH_FALSE;
		}
	}
	else
	{
		if ((xC == xT) && (yC == 1) && (yT == 2 || yT == 3))
		{
			flag = (((yT == 2) && (!target)) || ((yT == 3) && (!target) && !(LPawn*)game->getFigure(2, xT)))
				? (L_PATH_TRUE) : (L_PATH_FALSE);
		}
		else if (target && (target->color != this->color) && ((abs(xC - xT) == 1) && ((yT - yC) == 1)))
		{
			flag = L_PATH_TRUE;
		}
		else if (!target && (xC == xT) && (yT - yC == 1))
		{
			flag = L_PATH_TRUE;
		}
		else
		{
			flag = L_PATH_FALSE;
		}
	}

	if (flag)
	{
		if (this->color == L_COLOR_WHITE && yT == 0)
		{
			flag |= L_PATH_TRANSFORMATION;
		}
		else if (this->color == L_COLOR_BLACK && yT == 7)
		{
			flag |= L_PATH_TRANSFORMATION;
		}
	}

	return flag;
}

QString LPawn::getName() const
{
	return "Pawn";
}