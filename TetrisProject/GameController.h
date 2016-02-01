#pragma once

#include "Graphics.h"
#include "Block.h"

#include <vector>

class GameController
{

public:
	enum BlockType
	{
		STRAIT,
		SQUARE,
		Z,
		S,
		L,
		J,
		T,
		EMPTY
	};

public:	
	static void SwitchBlock(Block* block);
	
	static void Render(Graphics* gfx);
	static void Update();

	static void Init();

	static void Left();

	static void Right();

	static void Pause();

	static void Up();

	static void Drop();

	static void FinishedBlock();

	static BlockType mBoard[10][21];

	static int GetLevel();

	static void DrawPieces(int &i, int &j, Graphics* gfx);

private:
	GameController() { }; //Singleton Class

	~GameController() { };

	static Block* mCurrentBlock;

	static void CheckLineClears();

	static void GenerateBlock();

	static void GameOver();

	static double mScore;

	static int mLineCounter;

	static int mLevel;

	static BlockType mNextBlock;
};

