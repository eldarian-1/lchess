#include "LAverageBot.h"

#include <QVector>

#include "LBotTree.h"
#include "LBoard.h"
#include "LPath.h"
#include "LSquare.h"
#include "LFigure.h"

LBotTree* LAverageBot::botTree = new LBotTree;

void LAverageBot::clearTree()
{
	botTree->clear();
}

LPath* LAverageBot::calculateBestMove()
{
	this->minimax();

	LPath* path = nullptr;

	int size = botTree->getSize();

	int index = -1, value = 0;

	for (int i = 0; i < size; i++)
	{
		int tempValue = (*botTree)[i]->getValue();

		if (value <= tempValue)
		{
			index = i;
			value = tempValue;
		}
	}

	if (index != -1)
	{
		path = (*botTree)[index]->getPath();
	}

	clearTree();

	return path;
}

void LAverageBot::minimax(LBotTree* botTree, int depth, bool itsMe)
{
	LBoard* board;

	if (!botTree)
	{
		botTree = LAverageBot::botTree;
		board = this->board;
	}
	else
	{
		board = botTree->getBoard();
	}

	QVector<LPath*> paths = this->uglyMoves(itsMe, botTree->getBoard());
	int size = paths.size();

	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			LPath*& tempPath = paths[i];

			LSquare* from = tempPath->getFrom();
			LSquare* to = tempPath->getTo();

			int fromVer = from->getVertical();
			int fromHor = from->getHorizontal();

			int toVer = to->getVertical();
			int toHor = to->getHorizontal();

			LFigure* figure = board->getFigure(toVer, toHor);
			int value = 0;

			if (figure)
			{
				value = figure->getValue();
			}

			LBotTree* tempTree = botTree->addChild(board, tempPath, value);

			if (depth > 0)
			{
				minimax(tempTree, depth + (itsMe) ? (-1) : (0), !itsMe);
			}
		}
	}
}
