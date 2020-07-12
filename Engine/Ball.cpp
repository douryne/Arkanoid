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

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::CollidingWithWall(const RectF& wall)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < wall.left)
	{
		pos.x += wall.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > wall.right)
	{
		pos.x -= rect.right - wall.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < wall.top)
	{
		pos.y += wall.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > wall.bottom)
	{
		pos.y -= rect.bottom - wall.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}
