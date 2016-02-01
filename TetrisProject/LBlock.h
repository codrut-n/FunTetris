#pragma once

#include "Block.h"

class LBlock : public Block
{
public:
	LBlock();
	~LBlock();

	void Unload() override;
	void Load() override;
	void RotateClockwise() override;
};

