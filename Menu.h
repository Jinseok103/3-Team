#pragma once
#include <iostream>
#include <conio.h>
#include "Draw.h"

#define MAGIC_KEY 224
#define SPACE 32

enum MAIN
{
	GAMESTART = 0,
	INFO,
	HIGHSCORE,
	QUIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

class Menu {
private:
	int num_menu;
	int y;
	int input;
	int mode;
	bool show;
	bool quit;
public:
	Menu();
	MAIN MainMenu();
	void StartMenu();
	void MusicMenu();
	void Info();
};


