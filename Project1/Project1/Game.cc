#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include "Game.h"
#pragma comment(lib, "winmm.lib")

#define TABLE_X 11
#define TABLE_Y 30
#define MUSIC1 272
#define MUSIC2 270
#define MUSIC3 222

int song_index = 0;
using namespace std;

GamePlay::GamePlay()
{
	gt = new GameTable(TABLE_X, TABLE_Y, -1);
	gt->DrawGameTable();
	gt->LoadHighScore(1, song_index);
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
			gt->ChangeHighScore(gt->GetScore(), song_index);
			break;
		}
		if (gt->CheckLevel())
			gt->NewBlock();
		gt->LevelUp();
	}
}

GamePlay::GamePlay(int n)
{
	start = clock();
	gt = new GameTable(TABLE_X, TABLE_Y, n);
	gt->DrawGameTable();
	gt->LoadHighScore(0, song_index);
	gt->DrawScoreBoard();
	while (true) {
		gt->CheckKey();
		gt->CheckPassNote();
		system("cls");
		gt->DrawGameTable();
		gt->DrawScoreBoard();
		gt->MoveBlock();
		Sleep(gt->GetSpeed());
		end = clock();
		if (CheckEndMusic(start, end, n, 0)) {
			gt->ChangeHighScore(gt->GetScore(), song_index);
			break;
		}
		if (gt->CheckLevel() && CheckEndMusic(start, end, n, 1))
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
		song_index = 0;
		if (mode == 1) {
			PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"Luv Letter.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(0);
		}
		break;
	case 1:
		Quit();
		song_index = 1;
		if (mode == 1) {
			PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"Flower Dance.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(1);
		}
		break;
	case 2:
		Quit();
		song_index = 2;
		if (mode == 1) {
			PlaySound(L"I can't Beat Airman.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
			GamePlay();
		}
		else {
			PlaySound(L"I can't Beat Airman.wav", 0, SND_FILENAME | SND_ASYNC);
			GamePlay(2);
		}
		break;
	}
	PlaySound(NULL, 0, 0);
	DrawGameEnd(mode);
	DrawHighScore(music, mode);
	_getch();
}

bool GamePlay::CheckEndMusic(clock_t start, clock_t end, int music, int check)
{
	int playtime = static_cast<int>((end - start) / CLOCKS_PER_SEC);
	if (check == 0) {
		switch (music) {
		case 0:
			if (playtime > MUSIC1) return true;
			else return false;
		case 1:
			if (playtime > MUSIC2) return true;
			else return false;
		case 2:
			if (playtime > MUSIC3) return true;
			else return false;
		}
	}
	else if (check == 1) {
		switch (music) {
		case 0:
			if (playtime < MUSIC1 - 11) return true;
			else return false;
		case 1:
			if (playtime < MUSIC2 - 15) return true;
			else return false;
		case 2:
			if (playtime < MUSIC3 - 8) return true;
			else return false;
		}
	}
}
