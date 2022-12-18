#pragma once

#include "Graphics.h"
#include "Vec2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vec2& center,Graphics& gfx );
	static void DrawTitle(Graphics& gfx, int x, int y);
	static void DrawGameOver(Graphics& gfx, int x, int y);
};