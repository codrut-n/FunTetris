#pragma once
#include "Graphics.h"
#include "Block.h"

class SquareBlock : public Block
{
public:
	SquareBlock();
	~SquareBlock();

	void Load() override;
	void Unload() override;
	void RotateClockwise() override;
};

