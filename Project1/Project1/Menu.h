#pragma once
#include <iostream>
#include <conio.h>
#include "Draw.h"

#define MAGIC_KEY 224
#define SPACE 32

enum MENU
{
	GAMESTART = 0,
	INFO,
	QUIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

MENU MainMenu();
void StartMenu();
void MusicMenu(int mode);
void Info();


