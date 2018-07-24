#pragma once
#include "Snek.h"
#include <random>


class Goal
{
public:
Goal();
Goal(int in_posX, int in_posY);

bool DetectBody(Snek& snek);
bool DetectEaten(Snek& snek);


void UpdateLocation(std::uniform_int_distribution<int> GDistx, std::uniform_int_distribution<int> GDisty, std::mt19937 rng, Snek& snek );

Coordenada pos;
Color c = Colors::Magenta;
int Contador = 0;


};

