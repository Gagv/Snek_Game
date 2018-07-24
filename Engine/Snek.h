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
		Color c = Colors::Green;
		Coordenada pos_seg;

	};

	void UpdateHead();
	void Grow();


	int largo = 0;
	Color ColorHead = Colors::Cyan;
	Coordenada Head = { 3, 3, ColorHead };
	static constexpr int LargoMax = 90;
	Segment segments[LargoMax];
	Keyboard& kbd;

};

