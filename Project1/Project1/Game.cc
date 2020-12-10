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
	gt = new GameTable(TABLE_X, TABLE_Y, -1);
	gt->DrawGameTable();
	gt->DrawScoreBoard();
	while (true) {
		gt->CheckKey();
		gt->CheckPassNote();
		system("cls");
		gt->DrawGameTable();
		gt->DrawScoreBoard();
		gt->MoveBlock();
		Sleep(gt->GetSpeed());
		if (gt->CheckLife()) {
			break;
		}
		if (gt->CheckLevel())
			gt->NewBlock();
		gt->LevelUp();
	}
}

GamePlay::GamePlay(int n)
{
	gt = new GameTable(TABLE_X, TABLE_Y, n); 
	gt->DrawGameTable(); 
	gt->DrawScoreBoard();
	while (true) { 
		gt->CheckKey();
		gt->CheckPassNote();
		system("cls");
		gt->DrawGameTable();
		gt->DrawScoreBoard();
		gt->MoveBlock();
		Sleep(gt->GetSpeed());
		if (gt->CheckLevel())
			gt->NewBlock();
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
		if (mode == 1) {
			PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(0);
		}
		_getch();
		break;
	case 1:
		Quit();
		if (mode == 1) {
			PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(1);
		}
		_getch();
		break;
	case 2:
		Quit();
		if (mode == 1) {
			PlaySound(L"I can't Beat Airman.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"I can't Beat Airman.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(2);
		}
		_getch();
		break;
	}
}
