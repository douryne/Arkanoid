#include "Ball.h"

Ball::Ball(const Vec2& posIn, const Vec2& dirIn)
	:
	pos(posIn)
{
	SetDirection(dirIn);
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::CollidingWithWall(const Border& border)
{
	OverlapWithBottomWall = false;
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < border.left + border.borderWidth)
	{
		pos.x += border.left + border.borderWidth - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > border.right)
	{
		pos.x -= rect.right - border.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < border.top + border.borderWidth)
	{
		pos.y += border.top + border.borderWidth - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom + border.borderWidth > border.bottom)
	{
		pos.y -= rect.bottom + border.borderWidth - border.bottom;
		ReboundY();
		OverlapWithBottomWall = true;
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

Vec2 Ball::GetVelocity()
{
	return vel;
}

Vec2 Ball::GetPos()
{
	return pos;
}

void Ball::SetDirection(const Vec2& dir)
{
	vel = dir.GetNormalized() * speed;
}
