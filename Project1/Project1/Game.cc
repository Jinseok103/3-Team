#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include "Game.h"
#pragma comment(lib, "winmm.lib")

#define TABLE_X 11
#define TABLE_Y 30

using namespace std;

GamePlay::GamePlay()
{
	gt = new GameTable(TABLE_X, TABLE_Y);
	gt->DrawGameTable(); 
	gt->DrawScoreBoard();
	while (true) { 
		gt->CheckKey();
		system("cls");
		gt->DrawGameTable();
		gt->DrawScoreBoard();
		gt->MoveBlock();
		Sleep(gt->GetSpeed());
		if (gt->CheckLevel())
			gt->NewBlock();
		gt->LevelUp();
	}
}

GamePlay::~GamePlay() { 
	delete gt;
}


void StartGame(int music, int mode)
{
	switch (music)
	{
	case 0:
		Quit();
		PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC);
		GamePlay();
		_getch();
		break;
	case 1:
		Quit();
		PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC);
		GamePlay();
		_getch();
		break;
	case 2:
		Quit();
		PlaySound(L"I can't Beat Airman.wav", 0, SND_FILENAME | SND_ASYNC);
		GamePlay();
		_getch();
		break;
	}
}
