#pragma once

#include "LFigure.h"

class LRook final
	: public LFigure
{
private:
	bool _isWalked;

public:
	LRook(int color);

	void draw(LSquare* position, bool reverse) override;
	int isPossiblePath(LPath* path) override;

	virtual int getType() const override;
	virtual int getValue() const override;
	virtual QString getName() const override;

	bool isWalked() const;
	void setWalked(bool isWalked);

};
