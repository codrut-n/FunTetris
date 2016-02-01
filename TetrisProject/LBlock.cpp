#include "LBlock.h"
#include "GameConstants.cpp"

LBlock::LBlock()
{
}


LBlock::~LBlock()
{
}

void LBlock::Load()
{
	Block::Load();

	mRed = L_RED;
	mGreen = L_GREEN;
	mBlue = L_BLUE;

	mComponents[0].x = 5;
	mComponents[0].y = 2;
	mComponents[1].x = 5;
	mComponents[1].y = 1;
	mComponents[2].x = 5;
	mComponents[2].y = 0;
	mComponents[3].x = 6;
	mComponents[3].y = 2;
}

void LBlock::Unload()
{

}

void LBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		if (mComponents[0].x < 8)
		{
			mComponents[0].x = mComponents[0].x;
			mComponents[0].y = mComponents[0].y;
			mComponents[1].x = mComponents[0].x + 1;
			mComponents[1].y = mComponents[0].y;
			mComponents[2].x = mComponents[0].x + 2;
			mComponents[2].y = mComponents[0].y;
			mComponents[3].x = mComponents[0].x;
			mComponents[3].y = mComponents[0].y + 1;
			mDirection = RIGHT;
		}
	}
	else if (mDirection == RIGHT)
	{
		if (mComponents[0].x > 0)
		{
			mComponents[0].x = mComponents[0].x;
			mComponents[0].y = mComponents[0].y;
			mComponents[1].x = mComponents[0].x;
			mComponents[1].y = mComponents[0].y + 1;
			mComponents[2].x = mComponents[0].x;
			mComponents[2].y = mComponents[0].y + 2;
			mComponents[3].x = mComponents[0].x - 1;
			mComponents[3].y = mComponents[0].y;
			mDirection = DOWN;
		}
	}
	else if (mDirection == DOWN)
	{
		if (mComponents[0].x > 1)
		{
			mComponents[0].x = mComponents[0].x;
			mComponents[0].y = mComponents[0].y;
			mComponents[1].x = mComponents[0].x - 1;
			mComponents[1].y = mComponents[0].y;
			mComponents[2].x = mComponents[0].x - 2;
			mComponents[2].y = mComponents[0].y;
			mComponents[3].x = mComponents[0].x;
			mComponents[3].y = mComponents[0].y - 1;
			mDirection = LEFT;
		}
	}
	else if (mDirection == LEFT)
	{
		mComponents[0].x = mComponents[0].x;
		mComponents[0].y = mComponents[0].y;
		mComponents[1].x = mComponents[0].x;
		mComponents[1].y = mComponents[0].y - 1;
		mComponents[2].x = mComponents[0].x;
		mComponents[2].y = mComponents[0].y - 2;
		mComponents[3].x = mComponents[0].x + 1;
		mComponents[3].y = mComponents[0].y;
		mDirection = UP;
	}

}