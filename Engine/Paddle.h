#pragma once

#include "Ball.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(Vec2 posIn, float halfWidthIn, float halfHeightIn);
	bool CollidingWithBall(Ball& ball) const;
	void CollidingWithWall(const RectF& wall);
	void Update(const Keyboard& kbd, float dt);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	const int wingsWidth = 10;
	Color wingsColor = Colors::White;
	Color color = Colors::Red;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
	Vec2 pos;
};