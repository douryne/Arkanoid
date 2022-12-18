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
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetPos() - pos).x) || 
				ball.GetPos().x >= rect.left && ball.GetPos().x <= rect.right)
			{
				Vec2 dir;
				const float xDifference = ball.GetPos().x - pos.x;
				const float fixedXComponent = fixedZoneHalfWidth * exitXFactor;

				if (std::abs(xDifference) < fixedZoneHalfWidth)
				{
					if (xDifference < 0.0f)
					{
						dir = Vec2(-fixedXComponent, -1.0f);
					}
					else
					{
						dir = Vec2(fixedXComponent, -1.0f);
					}
				}
				else
				{
					dir = Vec2(xDifference * exitXFactor, -1.0f);
				}
				ball.SetDirection(dir);
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
	gfx.DrawRect(rect, Colors::Black);
	rect.left += 2;
	rect.right -= 2;
	gfx.DrawRect(rect, color);
}

void Paddle::CollidingWithWall(const Border& border)
{
	const RectF rect = GetRect();
	if (rect.left < border.left + border.borderPadding + border.borderWidth)
	{
		pos.x += border.left + border.borderPadding + border.borderWidth - rect.left;
	}
	if (rect.right > border.right - border.borderPadding)
	{
		pos.x -= rect.right - border.right + border.borderPadding;
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
