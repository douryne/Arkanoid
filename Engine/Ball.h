#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(const Vec2& posIn, const Vec2& velIn);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool CollidingWithWall(const RectF& wall);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVelocity();
	Vec2 GetPos();
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};