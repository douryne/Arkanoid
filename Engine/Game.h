/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "RectF.h"
#include "Brick.h"
#include "Paddle.h"
#include "Sound.h"
#include "Border.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	static constexpr float brickWidth = 60.0f;
	static constexpr float brickHeight = 30.0f;
	static constexpr int nBricksAcross = 10;
	static constexpr int nBricksDown = 5;
	static constexpr int nBricks = nBricksAcross * nBricksDown;
	FrameTimer ft;
	Ball ball;
	Brick bricks[nBricks];
	Brick brk;
	RectF walls;
	Paddle pad;
	Paddle padlive1;
	Paddle padlive2;
	Paddle padlive3;
	Border brd;
	Sound soundPad;
	Sound soundBrick;
	bool isStarted = false;
	bool isGameOver = false;
	int lives = 3;
	int countOfDestroyedBricks = 0;
	/********************************/
	/*  User Variables              */
	/********************************/
};