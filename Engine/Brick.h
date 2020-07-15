#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rectIn, Color colorIn);
	void Draw(Graphics& gfx);
	bool CollidingWithBall(Ball& ball);
private:
	static constexpr float padding = 2.0f;
	RectF rect;
	Color color;
	bool destroyed = false;
};