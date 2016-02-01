#pragma once
#include "Block.h"
class SBlock : public Block
{
public:
	SBlock();
	~SBlock();

	void Load() override;
	void Unload() override;
	void RotateClockwise() override;
};

