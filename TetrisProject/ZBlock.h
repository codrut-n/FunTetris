#pragma once
#include "Block.h"
class ZBlock : public Block
{
public:
	ZBlock();
	~ZBlock();

	void Load() override;
	void Unload() override;
	void RotateClockwise() override;
};

