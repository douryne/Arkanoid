#pragma once

#include "Graphics.h"

class Border
{
public:
	Border() = default;
	void DrawBorder(Graphics& gfx);
public:
	static constexpr float borderWidth = 15.0f;
	static constexpr float borderPadding = 5.0f;
	static constexpr Color borderColor = Colors::Blue;
	float x = 100.0f;
	float y = 40.0f;
	const float top = y;
	const float left = x;
	const float bottom = y + 500.0f + (borderWidth + borderPadding) * 2.0f;
	const float right = x + 600.0f + borderWidth + borderPadding * 2.0f;
};