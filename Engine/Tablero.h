#pragma once
#include "Graphics.h"
#include "Coordenada.h"
#include "Snek.h"
#include "Goal.h"

class Tablero
{
public:
	Tablero( Graphics& gfx);
	~Tablero();
	void DrawCelda(const Coordenada& coor) const;
	void Update( Snek& up_snek, Goal& up_goal);

	int PostJuegoX = 50;
	int PostJuegoY = 50;
	int dimCelda = 10;
	int ancho = 70;
	int largo = 50;
	Graphics& gfx;
	static constexpr int celdas = 3500; //ancho * largo
	Coordenada coors[celdas];
};

