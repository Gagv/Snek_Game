#include "Goal.h"


Goal::Goal()
{
};

Goal::Goal(int in_posX, int in_posY) {
	pos = { in_posX, in_posY, c };
}

bool Goal::DetectBody(Snek& snek) {                     // Detecta colision con snek. Unicamente para spawn
	for (int i = 0; i < snek.largo; i++)
	{
		if (pos == snek.segments[i].pos_seg)
		{
			return true;
		}
	}
	return false;
}

bool Goal::DetectEaten(Snek& snek) {                  // Detecta colision con Head
	if (pos == snek.segments[0].pos_seg)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Goal::UpdateLocation(std::uniform_int_distribution<int> GDistx, std::uniform_int_distribution<int> GDisty, std::mt19937 rng,Snek& snek) {             // Actualiza posicion de Goal

	while (DetectBody(snek))
	{
		int a = GDistx(rng);
		int b = GDistx(rng);
		pos = { a , b ,c };
	}
	Contador++;
}


