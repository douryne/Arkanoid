#pragma once

#include "Ball.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"
#include "Vec2.h"
#include "Border.h"

class Paddle
{
public:
	Paddle(Vec2 posIn, float halfWidthIn, float halfHeightIn);
	bool CollidingWithBall(Ball& ball);
	void CollidingWithWall(const Border& border);
	void Update(const Keyboard& kbd, float dt);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;
	void ResetCoolDown();

private:
	const int wingsWidth = 10;
	Color wingsColor = Colors::Cyan;
	Color color = Colors::White;
	float speed = 300.0f;
	float halfWidth;
	float halfHeight;
	float exitXFactor = 0.045f;
	float fixedZoneHalfWidth = 15.0f;
	Vec2 pos;
	bool isCoolDown = false;
};