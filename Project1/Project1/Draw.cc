#include <iostream>
#include <Windows.h>
#include <vector>
#include <ctime> 
#include <cstdlib> 
#include <algorithm> 
#include "Draw.h"
#include "Menu.h"

using namespace std;

void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void SetConsoleView()
{
	system("mode con:cols=50 lines=34");
	system("title RythmGame");
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void DrawMainMenu()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 7);
	cout << "******************************";
	gotoxy(10, 8);
	cout << "*         Rhythm Game        *";
	gotoxy(10, 9);
	cout << "******************************";
	gotoxy(20, 15);
	cout << "GameStart";
	gotoxy(20, 16);
	cout << "GameInfo";
	gotoxy(20, 17);
	cout << "Quit" << endl;
}

void DrawInfo()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 13);
	cout << "******************************";
	gotoxy(10, 14);
	cout << "        Developed BY          ";
	gotoxy(10, 15);
	cout << "        Choi In Tae           ";
	gotoxy(10, 16);
	cout << "        Kim Jin Seok          ";
	gotoxy(10, 17);
	cout << "        Jeong Yeun Keun       ";
	gotoxy(10, 18);
	cout << "******************************";
	system("pause>null");
}

void DrawStartMenu()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 7);
	cout << "******************************";
	gotoxy(10, 8);
	cout << "*      Select Game Mode      *";
	gotoxy(10, 9);
	cout << "******************************";
	gotoxy(20, 15);
	cout << "Normal Mode";
	gotoxy(20, 16);
	cout << "Infinity Mode";
	gotoxy(20, 17);
	cout << "GO BACK" << endl;
}

void DrawMusicMenu()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 7);
	cout << "******************************";
	gotoxy(10, 8);
	cout << "*        Select Music        *";
	gotoxy(10, 9);
	cout << "******************************";
	gotoxy(20, 15);
	cout << "Luv Letter";
	gotoxy(20, 16);
	cout << "Flower Dance";
	gotoxy(20, 17);
	cout << "I can't Beat Airman";
	gotoxy(20, 18);
	cout << "GO BACK" << endl;
}

/*void DrawGameover() 
{

}*/

void DrawUserCursor(int num_menu, int& y)
{
	if (y <= 0) y = 0;
	else if (y >= num_menu - 1) y = num_menu - 1;
	gotoxy(18, 15 + y);
	cout << ">";
}

bool Quit()
{
	system("cls");
	return TRUE;
}

GameTable::GameTable(int x, int y) {
	this->x = x;
	this->y = y;
	this->speed = 300;
	this->lv = 1;
	this->stage = 1;
	this->score = 0;
	this->cnt = 0;
	srand(time(NULL));
	for (int i = 0; i < y; i++) {
		vector<int> temp;
		for (int j = 0; j < x; j++) {
			temp.push_back(0);
		}
		table.push_back(temp);
	}
	for (int i = 0; i < x; i++) {
		table[0][i] = 1;
		table[y - 1][i] = 1;
	}
	for (int i = 1; i < y - 1; i++) {
		table[i][0] = 1;
		table[i][x - 1] = 1;
	}
	for (int i = 1; i < x - 1; i++) {
		table[y - 1][i] = 1;
	}

	for (int i = 0; i < x; i++) {
		keyboard.push_back(0);
	}
	keyboard[0] = 1;
	keyboard[2] = LEFT;
	keyboard[4] = UP;
	keyboard[6] = DOWN;
	keyboard[8] = RIGHT;
	keyboard[10] = 1;


	NewBlock();
}

void GameTable::DrawGameTable() {
	for (int i = 0; i < y - 5; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 1) cout << "¢Ë";
			else if (table[i][j] == LEFT) cout << "¢·";
			else if (table[i][j] == UP) cout << "¡â";
			else if (table[i][j] == DOWN) cout << "¡ä";
			else if (table[i][j] == RIGHT) cout << "¢¹";
			else cout << "  ";
		}
		cout << "\n";
	}
	for (int i = 0; i < x; i = i++) {
		if (keyboard[i] == 1) cout << "¢Ë";
		else if (keyboard[i] == 2) cout << "¢¸";
		else if (keyboard[i] == 3) cout << "¡ã";
		else if (keyboard[i] == 4) cout << "¡å";
		else if (keyboard[i] == 5) cout << "¢º";
		else if (keyboard[i] == LEFT) cout << "¢·";
		else if (keyboard[i] == UP) cout << "¡â";
		else if (keyboard[i] == DOWN) cout << "¡ä";
		else if (keyboard[i] == RIGHT) cout << "¢¹";
		else cout << "  ";
	}
	cout << "\n";
	for (int i = y - 4; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 1) cout << "¢Ë";
			else if (table[i][j] == LEFT) cout << "¢·";
			else if (table[i][j] == UP) cout << "¡â";
			else if (table[i][j] == DOWN) cout << "¡ä";
			else if (table[i][j] == RIGHT) cout << "¢¹";
			else cout << "  ";
		}
		cout << "\n";
	}
}

void GameTable::MoveBlock() {
	for (int i = y - 3; i > 1; i--) {
		table[i] = table[i - 1];
	}
	keyboard[2] = LEFT;
	keyboard[4] = UP;
	keyboard[6] = DOWN;
	keyboard[8] = RIGHT;
}

void GameTable::NewBlock() {
	int new_block = rand() % 4;
	switch (new_block) {
	case 0:
		table[2][2] = LEFT;
		break;
	case 1:
		table[2][4] = UP;
		break;
	case 2:
		table[2][6] = DOWN;
		break;
	case 3:
		table[2][8] = RIGHT;
		break;
	default:
		break;
	}
}

int GameTable::GetSpeed() {
	return speed;
}

void GameTable::CheckKey() {
	int key;

	if (_kbhit()) {
		key = _getch();
		if (key == 224) {
			key = _getch();
			switch (key) {
			case LEFT:
				keyboard[2] = 2;
				CheckCombo(2, LEFT);
				break;
			case UP:
				keyboard[4] = 3;
				CheckCombo(4, UP);
				break;
			case DOWN:
				keyboard[6] = 4;
				CheckCombo(6, DOWN);
				break;
			case RIGHT:
				keyboard[8] = 5;
				CheckCombo(8, RIGHT);
				break;
			default:
				break;
			}
		}
	}
}

void GameTable::CheckCombo(int i, int dir) {
	if (table[y - 5][i] == dir) {
		table[y - 5][i] = 0;
		score++;
		cnt++;
		gotoxy(24, 16); printf("        %6d", score);
	}
}

bool GameTable::CheckLevel() {
	if (lv < 5)
		lv++;
	else
		lv = stage;
	return (lv == 5) ? true : false;
}

void GameTable::DrawScoreBoard() {
	gotoxy(24, 15); printf(" YOUR SCORE :");
	gotoxy(24, 16); printf("        %6d", score);
}

void GameTable::LevelUp() {
	if (cnt < 5)
		return;
	switch (stage % 2) {
	case 1:
		stage++;
		break;
	case 0:
		speed -= 50;
		break;
	default:
		break;
	}
	cnt = 0;
	gotoxy(5, 15); printf(" LEVEL UP!!");
	Sleep(1000);
}
