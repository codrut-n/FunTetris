#define NOMINMAX

#include "StraitBlock.h"

StraitBlock::StraitBlock()
{
}


StraitBlock::~StraitBlock()
{
}

void StraitBlock::Load()
{
	Block::Load();

	mRed = 0.0f;
	mGreen = 0.5f;
	mBlue = 0.5f;

	mComponents[0].x = 5;
	mComponents[0].y = 0;
	mComponents[1].x = 5;
	mComponents[1].y = 1;
	mComponents[2].x = 5;
	mComponents[2].y = 2;
	mComponents[3].x = 5;
	mComponents[3].y = 3;
}


void StraitBlock::Unload()
{

}


void StraitBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		if (mComponents[1].x > 0 && mComponents[1].x < 8)
		{
			mComponents[0].x = mComponents[1].x - 1;
			mComponents[0].y = mComponents[1].y;
			mComponents[2].x = mComponents[1].x + 1;
			mComponents[2].y = mComponents[1].y;
			mComponents[3].x = mComponents[1].x + 2;
			mComponents[3].y = mComponents[1].y;
			mDirection = LEFT;
		}
	}
	else if (mDirection == LEFT)
	{
		mComponents[0].x = mComponents[1].x;
		mComponents[0].y = mComponents[1].y - 1;
		mComponents[2].x = mComponents[1].x;
		mComponents[2].y = mComponents[1].y + 1;
		mComponents[3].x = mComponents[1].x;
		mComponents[3].y = mComponents[1].y + 2;
		mDirection = UP;
	}
}