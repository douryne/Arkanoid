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

bool Brick::CollidingWithBall(Ball& ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		if (ball.GetPos().x >= rect.left && ball.GetPos().x <= rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		destroyed = true;
		return true;
	}
	return false;
}
