#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

void CursorView(char show);
void SetConsoleView();
void gotoxy(int x, int y);
void DrawMainMenu();
void DrawInfo();
void DrawStartMenu();
void DrawMusicMenu();
void DrawGameEnd(int mode);
void DrawHighScore(int music, int mode);
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
	int combo; 
	int combo_bonus;
	int life;
	fstream log_file;
	priority_queue<int, vector<int>, greater<int>> cur_highscore;
	int song;
	string music_name;
	int song_cur_highscore;
	int score_index[10];
public:
	GameTable(int x, int y, int n);
	void DrawGameTable();
	void MoveBlock();
	void NewBlock();
	int GetSpeed();
	int GetScore();
	void CheckKey();
	void CheckCombo(int i, int dir);
	bool CheckLevel();
	void DrawScoreBoard();
	void LevelUp();
	void CheckPassNote();
	bool CheckLife();
	void LoadHighScore(int song_index);
	void ChangeHighScore(int new_score, int song_index);
};
