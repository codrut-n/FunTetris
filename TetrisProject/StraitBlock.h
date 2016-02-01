#pragma once
#include "Block.h"
#include "Graphics.h"

class StraitBlock : public Block
{
public:
	StraitBlock();
	~StraitBlock();

	void Load() override;
	void Unload() override;
	void RotateClockwise() override;
};

