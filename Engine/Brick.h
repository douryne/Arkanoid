#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Vec2.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rectIn, Color colorIn);
	void Draw(Graphics& gfx);
	bool CheckballCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter() const;
private:
	static constexpr float padding = 2.0f;
	RectF rect;
	Color color;
	bool destroyed = false;
};