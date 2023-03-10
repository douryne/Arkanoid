#include "RectF.h"

RectF::RectF(float leftIn, float topIn, float rightIn, float bottomIn)
	:
	left(leftIn),
	right(rightIn),
	top(topIn),
	bottom(bottomIn)
{
}

RectF::RectF(const Vec2& topLeft, const Vec2& bottomRight)
	:
	RectF(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

RectF::RectF(const Vec2& topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vec2(width, height))
{
}

bool RectF::IsOverlappingWith(const RectF& other) const
{
	return right > other.left &&
		left < other.right &&
		bottom > other.top &&
		top < other.bottom;
}

RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

RectF RectF::GetExpanded(float offset)
{
	return RectF(left - offset, top - offset, right + offset, bottom + offset);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2, (top + bottom) / 2);
}
