#include <assert.h>
#include "Brick.h"
#include <iostream>

Brick::Brick(const RectF& rectIn, Color colorIn, int hp)
	:
	rect(rectIn),
	color(colorIn),
	brickHp(hp)
{
}

void Brick::Draw(Graphics& gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::CheckballCollision(const Ball& ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckballCollision(ball));

	const Vec2 ballPos = ball.GetPos();


	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	if (brickHp - 500 == 0)
	{
		destroyed = true;
	}
	else
	{
		brickHp -= 500;
	}
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

bool Brick::Destroyed() const
{
	return destroyed;
}
