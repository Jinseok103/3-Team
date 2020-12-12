#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Game.h"

using namespace std;

Menu::Menu() {
	quit = false;
	while (!quit)
	{
		switch (MainMenu())
		{
		case GAMESTART :
			show = false;
			StartMenu();
			break;
		case INFO :
			Info();
			break;
		case HIGHSCORE :
			show = true;
			StartMenu();
			break;
		case QUIT :
			quit = Quit();
			break;
		}
	}
}

MAIN Menu::MainMenu()
{
	y = 0;
	input = 0;
	while (true)
	{
		num_menu = 4;
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
				return HIGHSCORE;
			case 3:
				return QUIT;
			}
		}
	}
}

void Menu::StartMenu()
{
	y = 0;
	input = 0;
	while (true)
	{
		num_menu = 3;
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
				mode = 0;
				MusicMenu();
				break;
			case 1:
				mode = 1;
				MusicMenu();
				break;
			case 2:
				return;
			}
		}
	}
}

void Menu::MusicMenu()
{
	y = 0;
	input = _getch();
	while (true)
	{
		num_menu = 4;
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
				if(!show)
					StartGame(0, mode);
				else
					DrawHighScore(0, mode);
				return;
				break;
			case 1:
				if (!show)
					StartGame(1, mode);
				else
					DrawHighScore(1, mode);
				return;
				break;
			case 2:
				if (!show)
					StartGame(2, mode);
				else
					DrawHighScore(2, mode);
				return;
				break;
			case 3:
				return;
			}
		}
	}
}

void Menu::Info()
{
	DrawInfo();
}