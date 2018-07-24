#include "Tablero.h"
#include "Graphics.h"




Tablero::Tablero(Graphics& in_gfx)
	:
	gfx(in_gfx)
{
	for (int i = 0; i < ancho + 1; i++)
	{
		for (int j = 0; j < largo; j++)
		{
			coors[i*largo + j] = { i ,j, Colors::White };
			
		}
	}
}

Tablero::~Tablero()
{
}


void Tablero::DrawCelda(const Coordenada& coor) const
{
	gfx.DrawRectDim(PostJuegoX + coor.x * dimCelda, PostJuegoY + coor.y * dimCelda, dimCelda, dimCelda, coor.c);
	
}

void Tablero::Update(Snek& up_snek, Goal& up_goal)
{
	for (int i = 0; i < celdas; i++)
	{
		bool gotoBreakLoop = false;
		for (int j = 0; j < up_snek.largo && !gotoBreakLoop; j++)
		{
			if (coors[i] == up_snek.segments[j].pos_seg)
			{
				coors[i].c = up_snek.segments[j].pos_seg.c;
				gotoBreakLoop = true;
			}
			else
			{
				coors[i].c = Colors::White;
			}
		}
		
		if (coors[i] == up_goal.pos)
		{
			coors[i].c = up_goal.pos.c;
		}

	}
}
