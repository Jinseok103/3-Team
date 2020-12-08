#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
//#include "Draw.h"
#include "Game.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

void StartGame(int music, int mode)
{
	switch (music)
	{
	case 0:
		PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC);
		_getch();
		break;
	case 1:
		PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC);
		_getch();
		break;
	case 2:
		PlaySound(L"I can't Beat Airman", 0, SND_FILENAME | SND_ASYNC);
		_getch();
		break;
	}
}
