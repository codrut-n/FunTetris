#include "TBlock.h"
#include "GameConstants.cpp"


TBlock::TBlock()
{
}


TBlock::~TBlock()
{
}

void TBlock::Load()
{
	Block::Load();

	mRed = T_RED;
	mGreen = T_GREEN;
	mBlue = T_BLUE;

	mComponents[0].x = 5;
	mComponents[0].y = 1;
	mComponents[1].x = 5;
	mComponents[1].y = 0;
	mComponents[2].x = 4;
	mComponents[2].y = 1;
	mComponents[3].x = 6;
	mComponents[3].y = 1;
}

void TBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		mComponents[0].x = mComponents[0].x;
		mComponents[0].y = mComponents[0].y;
		mComponents[1].x = mComponents[0].x;
		mComponents[1].y = mComponents[0].y - 1;
		mComponents[2].x = mComponents[0].x;
		mComponents[2].y = mComponents[0].y + 1;
		mComponents[3].x = mComponents[0].x + 1;
		mComponents[3].y = mComponents[0].y;
		mDirection = RIGHT;
	}
	else if (mDirection == RIGHT)
	{
		if (mComponents[0].x > 0)
		{
			mComponents[0].x = mComponents[0].x;
			mComponents[0].y = mComponents[0].y;
			mComponents[1].x = mComponents[0].x;
			mComponents[1].y = mComponents[0].y + 1;
			mComponents[2].x = mComponents[0].x - 1;
			mComponents[2].y = mComponents[0].y;
			mComponents[3].x = mComponents[0].x + 1;
			mComponents[3].y = mComponents[0].y;
			mDirection = DOWN;
		}
	}
	else if (mDirection == DOWN)
	{
		mComponents[0].x = mComponents[0].x;
		mComponents[0].y = mComponents[0].y;
		mComponents[1].x = mComponents[0].x - 1;
		mComponents[1].y = mComponents[0].y;
		mComponents[2].x = mComponents[0].x;
		mComponents[2].y = mComponents[0].y - 1;
		mComponents[3].x = mComponents[0].x;
		mComponents[3].y = mComponents[0].y + 1;
		mDirection = LEFT;
	}
	else if (mDirection == LEFT)
	{
		if (mComponents[0].x < 9)
		{
			mComponents[0].x = mComponents[0].x;
			mComponents[0].y = mComponents[0].y;
			mComponents[1].x = mComponents[0].x;
			mComponents[1].y = mComponents[0].y - 1;
			mComponents[2].x = mComponents[0].x - 1;
			mComponents[2].y = mComponents[0].y;
			mComponents[3].x = mComponents[0].x + 1;
			mComponents[3].y = mComponents[0].y;
			mDirection = UP;
		}
	}
}
