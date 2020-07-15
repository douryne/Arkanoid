#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& rectIn, Color colorIn);
	void Draw(Graphics& gfx);
	bool CollidingWithBall(Ball& ball);
private:
	RectF rect;
	Color color;
	bool destroyed = false;
};