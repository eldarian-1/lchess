#pragma once

#include "LFigure.h"

class LElephant final
	: public LFigure
{
public:
	LElephant(int color);

	void draw(LSquare* position, bool reverse) override;
	int isPossiblePosition(LSquare* oldPosition, LSquare* newPosition) override;
	QString getName() const override;

};