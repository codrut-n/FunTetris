#include "Block.h"

#include "GameConstants.cpp"
#include "GameController.h"

void Block::Load()
{
	mFinished = false;
	mDirection = UP;
	ySpeed = 5;
	mCurrentY = 0;
}

void Block::Render(Graphics * gfx)
{
	for (int i = 0; i < 4; i++)
	{
		//Shapes enter and move in the playing area one row of squares at a time, not the entire shape at once
		//Rule taken from the manual :)
		if (mComponents[i].y > 1) {
			gfx->DrawRectangle(mComponents[i].x * BLOCK_WIDTH, mComponents[i].y * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
			gfx->FillRectangle(mComponents[i].x * BLOCK_WIDTH, mComponents[i].y * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, mRed, mGreen, mBlue, 1.0f);
		}
		
	}
}

void Block::Update()
{
	mCurrentY += ySpeed;
	//drop speed according to level
	if ( mCurrentY < (500/GameController::GetLevel()) )
	{
		return;
	}
	//check collision or board bottom and sets flag
	for (int i = 0; i < 4; i++)
	{
		int x = mComponents[i].x;
		int y = mComponents[i].y + 1;
		if (GameController::mBoard[x][y] != GameController::BlockType::EMPTY || y == 21)
		{
			mFinished = true;
			return;
		}
	}
	//pull down the piece
	for (int i = 0; i < 4; i++)
	{
		mComponents[i].y++;
	}
	mCurrentY = 0;
}

void Block::Left()
{
	for (int i = 0; i < 4; i++)
	{
		int x = mComponents[i].x;
		x--;

		if (x < 0)
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		mComponents[i].x -= 1;
	}
}

void Block::Right()
{
	for (int i = 0; i < 4; i++)
	{
		int x = mComponents[i].x;
		x ++;

		if (x > 9)
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		mComponents[i].x += 1;
	}
}

void Block::Pause()
{
	if (ySpeed == 0)
		ySpeed = 5;
	else
		ySpeed = 0;

}

void Block::RotateClockwise()
{
	if (mDirection == UP)
	{
		mDirection = RIGHT;
	}
	else if (mDirection == RIGHT)
	{
		mDirection = DOWN;
	}
	else if (mDirection == DOWN)
	{
		mDirection = LEFT;
	}
	else if (mDirection == LEFT)
	{
		mDirection = UP;
	}
}

void Block::Drop()
{
	while (!mFinished)
	{
		Update();
	}
}