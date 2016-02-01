#pragma once
#include "Graphics.h"

struct RenderableBlock
{
	int x;
	int y;
};

class Block
{
public:

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	
	int ySpeed;
	Direction mDirection;
	bool mFinished;
	int mCurrentY;
	RenderableBlock mComponents[4];

	float mRed;
	float mGreen;
	float mBlue;

	virtual void Load();
	virtual void Unload() = 0;
	virtual void Render(Graphics* gfx);
	virtual void Update();
	virtual void Left();
	virtual void Right();
	virtual void RotateClockwise();
	virtual void Pause();
	virtual void Drop();
};

