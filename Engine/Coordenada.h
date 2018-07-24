#pragma once
#include "Graphics.h"

class Coordenada
{
public:
	Coordenada();
	Coordenada(int in_x, int in_y, Color c);
	Coordenada(int in_x, int in_y);
	~Coordenada();
	
	bool operator==(const Coordenada& com) const {

		return x == com.x && y == com.y;
	}

	int x;
	int y;
	Color c;


};

