#pragma once
#include "Coordenada.h"
#include "Keyboard.h"

class Snek
{
public:
	Snek(Keyboard& kbd);
	~Snek();

	class Segment {
	public:
		Segment() {

		}
		Segment(Coordenada& in_pos)
			:
			pos_seg (in_pos),
			c (in_pos.c)
		{
		}
		Color c;
		Coordenada pos_seg;

	};

	void Grow();                // Serpiente crece al comer un Goal, se crea un nuevo segmento en el arreglo
	void UpdateBody();          // Actualiza las posiciones de cada uno de los elementos del arreglo para seguir al enterior, menos la primera posicion
	void UpdateSnake();          // Toma el vector de movimiento y actualiza la posicion de la cabeza


	int largo = 1;
	Color ColorHead = Colors::Green;
	Color ColorCuerpo = Colors::Black;
	Coordenada inicio = { 3, 3, ColorHead };
	Segment Head = { inicio };               // Primer segmento del arreglo
	static constexpr int LargoMax = 3000;
	Segment segments[LargoMax];            // Guarda la posicion y color de cada uno de los segmentos
	Keyboard& kbd;
	Coordenada coorMov = { 1,0 };    // Vector de movimiento

};

