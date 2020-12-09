#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GameTable {
private:
	int x;
	int y;
	vector<vector<int>> table;
	vector<int> keyboard;
	int speed;
	int lv;
	int stage;
	int score;
	int cnt;
public:
	GameTable(int x, int y);

	void DrawGameTable();

	void MoveBlock();

	void NewBlock();

	int GetSpeed();

	void CheckKey();

	void CheckCombo(int i, int dir);

	boolean CheckLevel();

	void DrawScoreBoard();

	void LevelUp();
};

class GamePlay {
private:
	GameTable* gt;
public:
	GamePlay();
	~GamePlay();
};
