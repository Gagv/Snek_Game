#include "Snek.h"



Snek::Snek(Keyboard& kbd)
	:
	kbd(kbd)
{
}


Snek::~Snek()
{
}

void Snek::UpdateHead()
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		Head.y--;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		Head.y++;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		Head.x++;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		Head.x--;
	}

}

void Snek::Grow()
{
	segments[largo];
	largo++;
}
