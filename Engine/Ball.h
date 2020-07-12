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
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float radius = 7.0f;
};