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
		gfx.DrawRect(rect, color);
	}
}

bool Brick::CollidingWithBall(Ball& ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
