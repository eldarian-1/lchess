#pragma once

class LNewGame;
class LFigure;

class LGame
{
private:
	static LGame* instance;
	
	bool isChecked;

	int gameInstance;

protected:
	LGame();

	int getGameInstance() const;
	void changeGameInstance(int gameInstance);

public:
	static LGame* getInstance();

	static void newGame(LNewGame* dialog);

	virtual LFigure* getFigure(int vertical, int horizontal) = 0;
	virtual void draw() = 0;

	virtual int isCheck(int color) = 0;
	virtual int isCheck(int color, int v, int h, int vK = -1, int hK = -1) = 0;
	virtual int getIsCheck() const = 0;

	virtual int isMat(int color) = 0;
	virtual bool isPat(int color) = 0;

	virtual void mousePress(int vertical, int horizontal) = 0;
	virtual void mouseRelease(int vertical, int horizontal) = 0;
	virtual void mouseMotionMove(int vertical, int horizontal) = 0;
	virtual void mouseMove(int vertical, int horizontal) = 0;

	void setChecked(bool isChecked);
	virtual void checked() = 0;
	virtual void unchecked() = 0;

	virtual void clear() = 0;

};
