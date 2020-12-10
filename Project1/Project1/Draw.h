#pragma once
#include <iostream>
#include <vector>

using namespace std;

void CursorView(char show);
void SetConsoleView();
void gotoxy(int x, int y);
void DrawMainMenu();
void DrawInfo();
void DrawStartMenu();
void DrawMusicMenu();
//void DrawGameover();
void DrawUserCursor(int num_menu, int& y);
bool Quit();

class GameTable {
private:
	int x;
	int y;
	int mode;
	vector<vector<int>> table;
	vector<int> keyboard;
	int speed;
	int lv;
	int stage;
	int score;
	int cnt;
	int life;
public:
	GameTable(int x, int y, int n);
	void DrawGameTable();
	void MoveBlock();
	void NewBlock();
	int GetSpeed();
	void CheckKey();
	void CheckCombo(int i, int dir);
	bool CheckLevel();
	void DrawScoreBoard();
	void LevelUp();
	void CheckPassNote();
	bool CheckLife();
};
