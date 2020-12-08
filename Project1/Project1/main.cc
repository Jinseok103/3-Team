#include <iostream>
#include "Draw.h"
#include "Menu.h"

#define _CRT_NO_WARNINGS

int main(void)
{
	SetConsoleView();
	while (true)
	{
		switch (MainMenu())
		{
		case GAMESTART:
			StartMenu();
			break;
		case INFO:
			Info();
			break;
		case QUIT:
			Quit();
			return 0;
		}
	}
	return 0;
}