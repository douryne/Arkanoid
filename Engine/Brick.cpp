#include <assert.h>
#include "Brick.h"

Brick::Brick(const RectF& rectIn, Color colorIn)
	:
	rect(rectIn),
	color(colorIn)
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
	if (ball.GetPos().x >= rect.left && ball.GetPos().x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
