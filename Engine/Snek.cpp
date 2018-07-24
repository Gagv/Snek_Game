#include "Snek.h"



Snek::Snek(Keyboard& kbd)
	:
	kbd(kbd)
{
	segments[0] = Head;
}


Snek::~Snek()
{
}

void Snek::Grow()
{
	Coordenada aux = { segments[largo - 1].pos_seg.x , segments[largo - 1].pos_seg.y , ColorCuerpo };  // para que el primer segmento agregado no copie el color de la cabeza
	segments[largo] = { aux };  // Crea un segmento en la posicion del segmento anterior
	largo++;                                // Crece la serpiente
}


void Snek::UpdateBody()
{
	
	if ( largo > 1 ) // Hay al menos un segmento
	{
		for (int i = largo - 1 ; i > 0; i--)       // i > 0 Para no cambiar la posicion de la cabeza. {Largo - 1} para tomar la ultima posicion 
		{
			Coordenada aux = { segments[i - 1].pos_seg.x , segments[i - 1].pos_seg.y , ColorCuerpo };
			segments[i] = { aux };   // El ultimo copia la posicion del siguiente
		}
	}
}

void Snek::UpdateSnake()
{

	if (kbd.KeyIsPressed(VK_UP))
	{
		coorMov = { 0,-1 };
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		coorMov = { 0,1 };
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		coorMov = { 1,0 };
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		coorMov = { -1,0 };
	}

	if (kbd.KeyIsPressed(VK_SPACE))
	{
		Grow();
	}

	UpdateBody();

	segments[0].pos_seg.x += coorMov.x;
	segments[0].pos_seg.y += coorMov.y;


}
