#include "Ball.h"

Ball::Ball(const Vec2& posIn, const Vec2& velIn)
	:
	pos(posIn),
	vel(velIn)
{
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}
