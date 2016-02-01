#include "SquareBlock.h"
#include "GameConstants.cpp"


SquareBlock::SquareBlock()
{
}


SquareBlock::~SquareBlock()
{
}


void SquareBlock::Load()
{
	Block::Load();

	mRed = SQUARE_RED;
	mGreen = SQUARE_GREEN;
	mBlue = SQUARE_BLUE;

	mComponents[0].x = 5;
	mComponents[0].y = 1;
	mComponents[1].x = 4;
	mComponents[1].y = 1;
	mComponents[2].x = 5;
	mComponents[2].y = 0;
	mComponents[3].x = 4;
	mComponents[3].y = 0;
}


void SquareBlock::Unload()
{

}


void SquareBlock::RotateClockwise()
{

}