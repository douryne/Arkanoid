/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f + 24.0f, 300.0f), Vec2(-1.0f, -1.0f)),
	walls(0.0f, 0.0f, float(gfx.ScreenWidth), float(gfx.ScreenHeight)),
	pad(Vec2(400.0f, 500.0f), 50.0f, 10.0f),
	padlive1(Vec2(50.0f, 100.0f), 30.0f, 7.0f),
	padlive2(Vec2(50.0f, 150.0f), 30.0f, 7.0f),
	padlive3(Vec2(50.0f, 200.0f), 30.0f, 7.0f),
	soundBrick(L"Sounds\\arkbrick.wav"),
	soundPad(L"Sounds\\arkpad.wav")
{

	const Color colors[nBricksDown] = { Colors::Yellow, Colors::White, Colors::Cyan, Colors::Magenta, Colors::Green };

	const Vec2 topLeft(130.0f, 60.0f);
	
	int i = 0;

	for (int y = 0; y < nBricksDown; y++)
	{
		const Color c = colors[y];
		for (int x = 0; x < nBricksAcross; x++)
		{
			if (y == 4)
			{
				bricks[i] = Brick(RectF(topLeft + Vec2(x * 58.0f, y * 28.0f), brickWidth, brickHeight), c, 1000);
			}
			else
			{
				bricks[i] = Brick(RectF(topLeft + Vec2(x * 58.0f, y * 28.0f), brickWidth, brickHeight), c, 500);
			}
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	bool collisionHappened = false;
	float curColDistSq;
	int curColIdx;

	if (isStarted)
	{
		if (!isGameOver)
		{
			pad.Update(wnd.kbd, dt);
			pad.CollidingWithWall(brd);
			ball.Update(dt);

			for (int i = 0; i < nBricks; ++i)
			{
				if (bricks[i].CheckballCollision(ball))
				{
					float newColDistSq = (ball.GetPos() - bricks[i].GetCenter()).GetLengthSq();
					if (collisionHappened)
					{
						if (newColDistSq < curColDistSq)
						{
							curColDistSq = newColDistSq;
							curColIdx = i;
						}
					}
					else
					{
						curColDistSq = newColDistSq;
						curColIdx = i;
						collisionHappened = true;
					}
				}
			}

			if (collisionHappened)
			{
				pad.ResetCoolDown();
				bricks[curColIdx].ExecuteBallCollision(ball);
				if (bricks[curColIdx].Destroyed())
				{
					countOfDestroyedBricks++;
				}
				soundBrick.Play();
			}

			if (countOfDestroyedBricks == nBricks)
			{
				isStarted = false;
			}

			if (pad.CollidingWithBall(ball))
			{
				soundPad.Play();
			}

			if (ball.CollidingWithWall(brd))
			{
				if (ball.OverlapWithBottomWall)
				{
					if (lives <= 1)
					{
						isGameOver = true;
					}
					else
					{
						lives--;
						pad.ResetCoolDown();
						soundPad.Play();
					}
				}
				else
				{
					pad.ResetCoolDown();
					soundPad.Play();
				}
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
	
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		SpriteCodex::DrawTitle(gfx, 325, 211);
	}
	else
	{
		if (isGameOver)
		{
			SpriteCodex::DrawGameOver(gfx, 358, 268);
		}
		else
		{
			for (Brick& b : bricks)
			{
				b.Draw(gfx);
			}
			ball.Draw(gfx);
			pad.Draw(gfx);
			brd.DrawBorder(gfx);
			if (lives >= 3)
			{
				padlive1.Draw(gfx);
				padlive2.Draw(gfx);
				padlive3.Draw(gfx);
			}
			else if(lives >= 2)
			{
				padlive1.Draw(gfx);
				padlive2.Draw(gfx);
			}
			else
			{
				padlive1.Draw(gfx);
			}
		}
	}
}
