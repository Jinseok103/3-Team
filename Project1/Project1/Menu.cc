#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Game.h"

using namespace std;

MENU MainMenu()
{
	int num_menu = 3, y = 0;
	int input = 0;
	while (true)
	{
		DrawMainMenu();
		DrawUserCursor(num_menu, y);
		input = _getch();
		if (input == MAGIC_KEY)
		{
			switch (_getch()) {
			case UP:
				y--;
				break;
			case DOWN:
				y++;
				break;
			default:
				break;
			}
		}
		else if (input == SPACE)
		{
			switch (y)
			{
			case 0:
				return GAMESTART;
			case 1:
				return INFO;
			case 2:
				return QUIT;
			}
		}
	}
}

void StartMenu()
{
	int num_menu = 3, y = 0;
	int input = 0;
	while (true)
	{
		DrawStartMenu();
		DrawUserCursor(num_menu, y);
		input = _getch();
		if (input == MAGIC_KEY)
		{
			switch (_getch()) {
			case UP:
				y--;
				break;
			case DOWN:
				y++;
				break;
			default:
				break;
			}
		}
		else if (input == SPACE)
		{
			switch (y)
			{
			case 0:
				MusicMenu(0);
				break;
			case 1:
				MusicMenu(1);
				break;
			case 2:
				return;
			}
		}
	}
}

void MusicMenu(int mode)
{
	int num_menu = 4, y = 0;
	int input;
	while (true)
	{
		DrawMusicMenu();
		DrawUserCursor(num_menu, y);
		input = _getch();
		if (input == MAGIC_KEY)
		{
			switch (_getch()) {
			case UP:
				y--;
				break;
			case DOWN:
				y++; 
				break;
			default:
				break;
			}
		}
		else if (input == SPACE)
		{
			switch (y)
			{
			case 0:
				StartGame(0, mode);
				break;
			case 1:
				StartGame(1, mode);
				break;
			case 2:
				StartGame(2, mode);
				break;
			case 3:
				return;
			}
		}
	}
}


void Info()
{
	DrawInfo();
}

