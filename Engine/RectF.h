#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float leftIn, float topIn, float rightIn, float bottomIn);
	RectF(const Vec2& topLeft, const Vec2& bottomRight);
	RectF(const Vec2& topLeft, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;
public:
	float right;
	float left;
	float top;
	float bottom;
};