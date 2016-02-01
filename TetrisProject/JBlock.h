#pragma once

#include "Block.h"

class JBlock : public Block
{
public:
	JBlock();
	~JBlock();

	void Load() override;
	void Unload() override;
	void RotateClockwise() override;
};

