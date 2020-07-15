#include "Paddle.h"

Paddle::Paddle(Vec2 posIn, float halfWidthIn, float halfHeightIn)
	:
	pos(posIn),
	halfWidth(halfWidthIn),
	halfHeight(halfHeightIn)
{
}

bool Paddle::CollidingWithBall(Ball& ball) const
{
	if (ball.GetVelocity().y > 0.0f && GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingsColor);
	rect.left += wingsWidth;
	rect.right -= wingsWidth;
	gfx.DrawRect(rect, color);
}

void Paddle::CollidingWithWall(const RectF& wall)
{
	const RectF rect = GetRect();
	if (rect.left < wall.left)
	{
		pos.x += wall.left - rect.left;
	}
	if (rect.right > wall.right)
	{
		pos.x -= rect.right - wall.right;
	}
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
