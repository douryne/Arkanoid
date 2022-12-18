#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"
#include <random>
#include "Border.h"

class Ball
{
public:
	Ball(const Vec2& posIn, const Vec2& dirIn);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool CollidingWithWall(const Border& border);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity();
	Vec2 GetPos();
	void SetDirection(const Vec2& dir);
private:
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
public:
	bool OverlapWithBottomWall = false;
};