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
		if (coors[i] == up_snek.Head)
		{
			coors[i].c = up_snek.Head.c;
		}
		else
		{
			coors[i].c = Colors::White;
		}

		for (int i = 0; i < up_snek.largo; i++)
		{
			if (coors[i] == up_snek.segments[i].pos_seg)
			{
				coors[i].c = up_snek.segments[i].pos_seg.c;
			}
			else
			{
				coors[i].c = Colors::White;
			}
		}
	}
}
