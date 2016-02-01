#include "SBlock.h"
#include "GameConstants.cpp"


SBlock::SBlock()
{
}


SBlock::~SBlock()
{
}

void SBlock::Unload()
{

}

void SBlock::Load()
{
	Block::Load();

	mRed = S_RED;
	mGreen = S_GREEN;
	mBlue = S_BLUE;

	mComponents[0].x = 5;
	mComponents[0].y = 1;
	mComponents[1].x = 4;
	mComponents[1].y = 1;
	mComponents[2].x = 5;
	mComponents[2].y = 2;
	mComponents[3].x = 4;
	mComponents[3].y = 0;
}

void SBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		mComponents[1].x = mComponents[0].x;
		mComponents[1].y = mComponents[0].y - 1;
		mComponents[2].x = mComponents[0].x - 1;
		mComponents[2].y = mComponents[0].y;
		mComponents[3].x = mComponents[0].x + 1;
		mComponents[3].y = mComponents[0].y - 1;
		mDirection = RIGHT;
	}
	else if (mDirection == RIGHT)
	{
		mComponents[1].x = mComponents[0].x - 1;
		mComponents[1].y = mComponents[0].y;
		mComponents[2].x = mComponents[0].x - 1;
		mComponents[2].y = mComponents[0].y - 1;
		mComponents[3].x = mComponents[0].x;
		mComponents[3].y = mComponents[0].y + 1;
		mDirection = UP;
	}
}