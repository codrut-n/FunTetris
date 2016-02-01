#pragma once
#include "Block.h"
#include "Graphics.h"

class TBlock : public Block
{
public:
	TBlock();
	~TBlock();

	void Load() override;
	void Unload() override {};
	void RotateClockwise() override;
};

