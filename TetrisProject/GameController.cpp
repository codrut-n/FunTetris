#include "GameController.h"
#include "GameConstants.cpp"

#include "StraitBlock.h"
#include "TBlock.h"
#include "SquareBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "SBlock.h"
#include "ZBlock.h"

#include <sstream>

Block* GameController::mCurrentBlock;
GameController::BlockType GameController::mBoard[10][21];
double GameController::mScore;
int GameController::mLineCounter;
int GameController::mLevel;
GameController::BlockType GameController::mNextBlock;

void GameController::Init()
{
	mScore = 0;
	mLineCounter = 0;
	mLevel = 1;
	//clear board
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			mBoard[i][j] = EMPTY;
		}
	}

	mCurrentBlock = nullptr;
	
	int random = rand();

	switch (random)
	{
	case 0:
		mNextBlock = STRAIT;
		break;
	case 1:
		mNextBlock = T;
		break;
	case 2:
		mNextBlock = SQUARE;
		break;
	case 3:
		mNextBlock = J;
		break;
	case 4:
		mNextBlock = L;
		break;
	case 5:
		mNextBlock = S;
		break;
	case 6:
		mNextBlock = Z;
		break;
	}

	GenerateBlock();
}


void GameController::SwitchBlock(Block* block)
{
	block->Load();
	mCurrentBlock = block;
}

void GameController::Render(Graphics* gfx)
{
	gfx->ClearScreen(1.0f, 1.0f, 1.0f);

	std::stringstream ss;
	ss << "Score: ";
	ss << mScore;
	ss << "\nLines: ";
	ss << mLineCounter;
	ss << "\nLevel: ";
	ss << mLevel-1;

	gfx->DrawTextBox(350.0f, 50.0f, ss.str());
	//preview next piece
	switch (mNextBlock)
	{
	case STRAIT:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		
		gfx->DrawRectangle(350.0f, 100.0f + 3 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 3 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
		break;
	case T:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f - BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f - BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);

		break;
	case SQUARE:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
		break;
	case J:
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2 * BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
		break;
	case L:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
		break;
	case S:
		gfx->DrawRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
		break;
	case Z:
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f + BLOCK_HEIGHT, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		gfx->DrawRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f);
		gfx->FillRectangle(350.0f, 100.0f + 2*BLOCK_HEIGHT, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
		break;
	}

	//draw board
	for (int i = 0; i < 10; i++)
	{
		for (int j = 2; j < 21; j++)
		{
			gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f);
			if ((i + j) % 2 == 0)
			{
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.5f, 0.5f, 0.5f, 1.0f);
			}
			else
			{
				gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.4f, 0.4f, 0.4f, 1.0f);
			}
			
			DrawPieces(i, j, gfx);
		}
	}

	mCurrentBlock->Render(gfx);
}

void GameController::DrawPieces(int &i, int &j, Graphics* gfx) {
	if (mBoard[i][j] == STRAIT)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, STRAIT_RED, STRAIT_GREEN, STRAIT_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == T)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, T_RED, T_GREEN, T_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == SQUARE)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, SQUARE_RED, SQUARE_GREEN, SQUARE_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == L)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, L_RED, L_GREEN, L_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == J)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, J_RED, J_GREEN, J_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == S)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, S_RED, S_GREEN, S_BLUE, 1.0f);
	}
	else if (mBoard[i][j] == Z)
	{
		gfx->DrawRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 0.0f, 0.0f, 0.0f, 1.0f, 3.0f);
		gfx->FillRectangle(i * BLOCK_WIDTH, j * BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, Z_RED, Z_GREEN, Z_BLUE, 1.0f);
	}
}

void GameController::Update()
{
	mCurrentBlock->Update();
}

void GameController::Left()
{
	mCurrentBlock->Left();
}

void GameController::Right()
{
	mCurrentBlock->Right();
}

void GameController::Pause()
{
	mCurrentBlock->Pause();
}

void GameController::Up()
{
	mCurrentBlock->RotateClockwise();
}

void GameController::Drop()
{
	mCurrentBlock->Drop();
}

int GameController::GetLevel()
{
	return mLevel;
}

void GameController::FinishedBlock()
{
	if (mCurrentBlock->mFinished)
	{
		for (int i = 0; i < 4; i++)
		{
			int x = mCurrentBlock->mComponents[i].x;
			int y = mCurrentBlock->mComponents[i].y;

			if (y == 0) // Check For Game Over
			{
				GameOver();
				delete mCurrentBlock;

				GenerateBlock();

				Init();
				return;
			}

			//mark the board coordinates with the proper shape
			if (dynamic_cast<StraitBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = STRAIT;
			}
			else if (dynamic_cast<TBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = T;
			}
			else if (dynamic_cast<SquareBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = SQUARE;
			}
			else if (dynamic_cast<JBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = J;
			}
			else if (dynamic_cast<LBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = L;
			}
			else if (dynamic_cast<SBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = S;
			}
			else if (dynamic_cast<ZBlock*> (mCurrentBlock))
			{
				mBoard[x][y] = Z;
			}

		}
		CheckLineClears();
		delete mCurrentBlock;

		GenerateBlock();
	}
}

void GameController::CheckLineClears()
{
	int numberOfClearedLines = 0;

	for (int line = 21; line >= 2; line--)
	{
		int countBlocks = 0;
		for (int j = 0; j < 10; j++)
		{
			if (mBoard[j][line] != EMPTY)
			{
				countBlocks++;
			}
		}
		//if there is a full line
		if (countBlocks == 10)
		{

			numberOfClearedLines++;
			//marks the entries on the board empty on that full line
			for (int j = 0; j < 10; j++)
			{			
				mBoard[j][line] = EMPTY;
			}
			//pull down the lines above
			for (int k = line; k >= 1; k--)
			{
				for (int j = 0; j < 10; j++)
				{
					mBoard[j][k] = mBoard[j][k - 1];
				}
			}
			//increment the line so that it can check also the line that was just pulled down
			line++;
		}			
	}
	if (numberOfClearedLines != 0) {
		//update Line Counter and level
		mLineCounter += numberOfClearedLines;
		mLevel = (mLineCounter / 10) + 1;
		//increment score as per rule: 1 line = 1 point, 2 lines = 2 points, 3 lines = 4 points * level, etc
		mScore += mLevel * (pow(2, numberOfClearedLines-1));
	}
}

void GameController::GenerateBlock()
{
	int random = rand() % 7;

	if (mNextBlock == STRAIT)
	{
		GameController::SwitchBlock(new StraitBlock());
	}
	else if (mNextBlock == T)
	{
		GameController::SwitchBlock(new TBlock());
	}
	else if (mNextBlock == SQUARE)
	{
		GameController::SwitchBlock(new SquareBlock());
	}
	else if (mNextBlock == J)
	{
		GameController::SwitchBlock(new JBlock());
	}
	else if (mNextBlock == L)
	{
		GameController::SwitchBlock(new LBlock());
	}
	else if (mNextBlock == S)
	{
		GameController::SwitchBlock(new SBlock());
	}
	else if (mNextBlock == Z)
	{
		GameController::SwitchBlock(new ZBlock());
	}

	switch (random)
	{
	case 0:
		mNextBlock = STRAIT;
		break;
	case 1:
		mNextBlock = T;
		break;
	case 2:
		mNextBlock = SQUARE;
		break;
	case 3:
		mNextBlock = J;
		break;
	case 4:
		mNextBlock = L;
		break;
	case 5:
		mNextBlock = S;
		break;
	case 6:
		mNextBlock = Z;
		break;
	}

}

void GameController::GameOver()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			mBoard[i][j] = EMPTY;
		}
	}
}