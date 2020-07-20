#include "Paddle.h"
#include <iostream>

Paddle::Paddle(Vec2 posIn, float halfWidthIn, float halfHeightIn)
	:
	pos(posIn),
	halfWidth(halfWidthIn),
	halfHeight(halfHeightIn)
{
}

bool Paddle::CollidingWithBall(Ball& ball)
{
	RectF rect = GetRect();
	if (!isCoolDown)
	{
		if (rect.IsOverlappingWith(ball.GetRect()))
		{
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetPos() - pos).x))
			{
				ball.ReboundY();
			}
			else if (ball.GetPos().x >= rect.left && ball.GetPos().x <= rect.right)
			{
				ball.ReboundY();
			}
			else
			{
				ball.ReboundX();
			}
			isCoolDown = true;
			return true;
		}
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

void Paddle::ResetCoolDown()
{
	isCoolDown = false;
}
