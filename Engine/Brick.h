#pragma once

#include "RectF.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const RectF& rectIn, Color colorIn);
	void Draw(Graphics& gfx);
private:
	RectF rect;
	Color color;
	bool destroyed = false;
};