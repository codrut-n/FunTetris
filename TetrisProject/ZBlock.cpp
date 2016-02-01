#include "ZBlock.h"
#include "GameConstants.cpp"


ZBlock::ZBlock()
{
}


ZBlock::~ZBlock()
{
}

void ZBlock::Unload()
{
}

void ZBlock::Load()
{
	Block::Load();

	mRed = Z_RED;
	mGreen = Z_GREEN;
	mBlue = Z_BLUE;

	mComponents[0].x = 4;
	mComponents[0].y = 1;
	mComponents[1].x = 4;
	mComponents[1].y = 2;
	mComponents[2].x = 5;
	mComponents[2].y = 1;
	mComponents[3].x = 5;
	mComponents[3].y = 0;
}

void ZBlock::RotateClockwise()
{
	if (mDirection == UP)
	{
		if (mComponents[0].x > 0 && mComponents[0].x < 9)
		{
			mComponents[1].x = mComponents[0].x - 1;
			mComponents[1].y = mComponents[0].y - 1;
			mComponents[2].x = mComponents[0].x;
			mComponents[2].y = mComponents[0].y - 1;
			mComponents[3].x = mComponents[0].x + 1;
			mComponents[3].y = mComponents[0].y;
			mDirection = RIGHT;
		}
	}
	else if (mDirection == RIGHT)
	{
		if (mComponents[0].x > 0 && mComponents[0].x < 9)
		{
			mComponents[1].x = mComponents[0].x;
			mComponents[1].y = mComponents[0].y + 1;
			mComponents[2].x = mComponents[0].x + 1;
			mComponents[2].y = mComponents[0].y;
			mComponents[3].x = mComponents[0].x + 1;
			mComponents[3].y = mComponents[0].y - 1;
			mDirection = UP;
		}
	}
}