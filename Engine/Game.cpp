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
	tab(gfx),
	rng(rd()),
	GDistx (1,tab.ancho-1),
	GDisty(1, tab.largo-1),
	snek (wnd.kbd),
	goal ( GDistx(rng), GDisty(rng))

{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	MoveCount++;

	if (MoveCount >= FramesPerMove)
	{
		if (goal.DetectEaten(snek))
		{
			goal.UpdateLocation(GDistx, GDisty,rng,snek);
			snek.Grow();
		}


		snek.UpdateSnake();
		tab.Update(snek,goal);
		MoveCount = 0;
	}

	if (goal.Contador<5)
	{
		FramesPerMove = 5;
	}
	else if (goal.Contador>= 5 && goal.Contador<10)
	{
		FramesPerMove = 3;
	}
	else if (goal.Contador >= 10 && goal.Contador < 15)
	{
		FramesPerMove = 2;
	}
	else if (goal.Contador >= 15)
	{
		FramesPerMove = 1;
	}
}

void Game::ComposeFrame()
{

	for (int i = 0; i < tab.celdas; i++)
	{
		Color c = Colors::White;
		tab.DrawCelda(tab.coors[i]);
	}

}
