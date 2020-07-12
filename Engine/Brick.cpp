#include "Brick.h"

Brick::Brick(const RectF& rectIn, Color colorIn)
	:
	rect(rectIn),
	color(colorIn)
{
}

void Brick::Draw(Graphics& gfx)
{
	gfx.DrawRect(rect, color);
}
