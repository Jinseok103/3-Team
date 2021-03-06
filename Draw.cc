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
	cout << "HighScore";
	gotoxy(20, 18);
	cout << "Quit" << endl;
}

void DrawInfo()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 10); cout << "------------------------------";
	gotoxy(10, 11); cout << "      Developed BY Team 3     ";
	gotoxy(10, 12); cout << "        Choi In Tae           ";
	gotoxy(10, 13); cout << "        Kim Jin Seok          ";
	gotoxy(10, 14); cout << "       Jeong Yoon Keun        ";
	gotoxy(10, 15); cout << "------------------------------";
	gotoxy(9,  16); cout << "MUSIC1 : Luv Letter - DJ Okawari";
	gotoxy(8,  17); cout << "MUSIC2 : Flower Dance - DJ Okawari";
	gotoxy(11, 18); cout << "MUSIC3 : I can't Beat Airman";
	gotoxy(10, 19); cout << "------------------------------";
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

void DrawGameEnd(int mode)
{
	gotoxy(0, 11); printf("----------------------");
	gotoxy(0, 12); printf("                      ");
	if (mode == 1) {
		gotoxy(0, 13); printf("       Game Over      ");
	}
	else {
		gotoxy(0, 13); printf("       Game Clear     ");
	}
	gotoxy(0, 14); printf("                      ");
	gotoxy(0, 15); printf("----------------------");
	system("pause>null");
}

void DrawHighScore(int music, int mode)
{
	system("cls");
	string line;
	string init_line = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
	fstream log_file;
	if (mode == 0) {				
		switch (music) {
		case 0:
			log_file.open("Luv_Letter_normal.txt", ios::in);
			break;
		case 1:
			log_file.open("Flower_Dance_normal.txt", ios::in);
			break;
		case 2:
			log_file.open("Airman_normal.txt", ios::in);
			break;
		default:
			break;
		}
	}
	else {							
		switch (music) {
		case 0:
			log_file.open("Luv_Letter_inf.txt", ios::in);
			break;
		case 1:
			log_file.open("Flower_Dance_inf.txt", ios::in);
			break;
		case 2:
			log_file.open("Airman_inf.txt", ios::in);
			break;
		default:
			break;
		}
	}
	gotoxy(10, 3);
	cout << "**********High Score**********";
	if (log_file.is_open()) {
		log_file.seekg(0, ios::beg);
		for (int i = 0; i < 10; i++) {
			getline(log_file, line);
			gotoxy(13, 6 + 2 * i);
			if (i != 9)
				cout << "No. " << i + 1 << " " << stoi(line);
			else
				cout << "No." << i + 1 << " " << stoi(line);
		}
	}
	else {
		if (mode == 0) {				
			switch (music) {
			case 0:
				log_file.open("Luv_Letter_normal.txt", ios::app);
				break;
			case 1:
				log_file.open("Flower_Dance_normal.txt", ios::app);
				break;
			case 2:
				log_file.open("Airman_normal.txt", ios::app);
				break;
			default:
				break;
			}
		}
		else {							
			switch (music) {
			case 0:
				log_file.open("Luv_Letter_inf.txt", ios::app);
				break;
			case 1:
				log_file.open("Flower_Dance_inf.txt", ios::app);
				break;
			case 2:
				log_file.open("Airman_inf.txt", ios::app);
				break;
			default:
				break;
			}
		}
		log_file.write(init_line.c_str(), init_line.size());
		for (int i = 0; i < 10; i++) {
			gotoxy(13, 6 + 2 * i);
			if (i != 9)
				cout << "No. " << i + 1 << " " << 0;
			else
				cout << "No." << i + 1 << " " << 0;
		}
	}
	log_file.close();
	system("pause>null");
}

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

GameTable::GameTable(int x, int y, int n) {
	this->x = x;
	this->y = y;
	this->mode = n;
	this->speed = 300 - n * 100;
	this->lv = n;
	this->stage = n + 2;
	this->score = 0;
	this->cnt = 0;
	this->combo = 0;
	this->combo_bonus = 1;
	this->life = 3;
	for (int i = 0; i < 10; i++)
		this->cur_highscore.push(0);
	this->song_cur_highscore = 0;
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
			if (table[i][j] == 1) cout << "��";
			else if (table[i][j] == LEFT) cout << "��";
			else if (table[i][j] == UP) cout << "��";
			else if (table[i][j] == DOWN) cout << "��";
			else if (table[i][j] == RIGHT) cout << "��";
			else cout << "  ";
		}
		cout << "\n";
	}
	for (int i = 0; i < x; i = i++) {
		if (keyboard[i] == 1) cout << "��";
		else if (keyboard[i] == 2) cout << "��";
		else if (keyboard[i] == 3) cout << "��";
		else if (keyboard[i] == 4) cout << "��";
		else if (keyboard[i] == 5) cout << "��";
		else if (keyboard[i] == LEFT) cout << "��";
		else if (keyboard[i] == UP) cout << "��";
		else if (keyboard[i] == DOWN) cout << "��";
		else if (keyboard[i] == RIGHT) cout << "��";
		else cout << "  ";
	}
	cout << "\n";
	for (int i = y - 4; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (table[i][j] == 1) cout << "��";
			else if (table[i][j] == LEFT) cout << "��";
			else if (table[i][j] == UP) cout << "��";
			else if (table[i][j] == DOWN) cout << "��";
			else if (table[i][j] == RIGHT) cout << "��";
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

int GameTable::GetScore() {
	return score;
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
		score = score + combo_bonus * 100;
		cnt++;
		combo++;
		combo_bonus = combo_bonus + (combo / 10);
		gotoxy(24, 16); printf("        %6d", score);
		gotoxy(24, 18); printf("        %6d", combo);
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
	if (mode == -1) {
		gotoxy(24, 5); printf(" YOUR LIFE :");
		gotoxy(24, 6); printf("        %6d", life);
	}
	gotoxy(24, 15); printf(" YOUR SCORE :");
	gotoxy(24, 16); printf("        %6d", score);
	gotoxy(24, 17); printf(" COMBO : ");			// changed
	gotoxy(24, 18); printf("        %6d", combo);

	gotoxy(24, 3);  printf(" %s", music_name.c_str());
	gotoxy(24, 19); printf(" HIGH SCORE : ");
	if (score < song_cur_highscore) {
		gotoxy(24, 20); printf("        %6d", song_cur_highscore);
	}
	else {
		gotoxy(24, 20); printf("        %6d", score);
	}
}

void GameTable::LevelUp() {
	if (cnt < 5)
		return;
	switch (stage % 4) {
	case 1:
		stage++;
		break;
	default:
		speed -= 50;
		break;
	}
	cnt = 0;
	gotoxy(5, 13); printf(" LEVEL UP!!");
	Sleep(1000);
}

void GameTable::CheckPassNote() {
	for (int i = 2; i <= 8; i = i + 2)
		if (table[y - 4][i] != 0) {
			combo = 0;
			combo_bonus = 1;
			life--;
			gotoxy(24, 18); printf("        %6d", combo);
		}
}

bool GameTable::CheckLife() {
	return (life == 0) ? true : false;
}

void GameTable::LoadHighScore(int song_index)
{
	string line;
	string init_line = "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";

	if (mode != -1) {				// normal
		switch (song_index) {
		case 0:
			music_name = "Luv_Letter";
			log_file.open("Luv_Letter_normal.txt", ios::in);
			break;
		case 1:
			music_name = "Flower_Dance";
			log_file.open("Flower_Dance_normal.txt", ios::in);
			break;
		case 2:
			music_name = "I can't Beat Airman";
			log_file.open("Airman_normal.txt", ios::in);
			break;
		default:
			break;
		}
	}
	else {							// inf
		switch (song_index) {
		case 0:
			music_name = "Luv_Letter";
			log_file.open("Luv_Letter_inf.txt", ios::in);
			break;
		case 1:
			music_name = "Flower_Dance";
			log_file.open("Flower_Dance_inf.txt", ios::in);
			break;
		case 2:
			music_name = "I can't Beat Airman";
			log_file.open("Airman_inf.txt", ios::in);
			break;
		default:
			break;
		}
	}

	if (log_file.is_open()) {

		log_file.seekg(0, ios::beg);
		getline(log_file, line);
		cur_highscore.pop();
		cur_highscore.push(stoi(line));
		song_cur_highscore = stoi(line);
	}
	else {
		if (mode != -1) {				// normal
			switch (song_index) {
			case 0:
				log_file.open("Luv_Letter_normal.txt", ios::app);
				break;
			case 1:
				log_file.open("Flower_Dance_normal.txt", ios::app);
				break;
			case 2:
				log_file.open("Airman_normal.txt", ios::app);
				break;
			default:
				break;
			}
		}
		else {							// inf
			switch (song_index) {
			case 0:
				log_file.open("Luv_Letter_inf.txt", ios::app);
				break;
			case 1:
				log_file.open("Flower_Dance_inf.txt", ios::app);
				break;
			case 2:
				log_file.open("Airman_inf.txt", ios::app);
				break;
			default:
				break;
			}
		}

		log_file.write(init_line.c_str(), init_line.size());
	}
	log_file.close();
}

void GameTable::ChangeHighScore(int new_score, int song_index) {
	string line;
	string new_high_score;
	int tmp[20];

	if (mode != -1) {				// normal
		switch (song_index) {
		case 0:
			log_file.open("Luv_Letter_normal.txt", ios::out);
			break;
		case 1:
			log_file.open("Flower_Dance_normal.txt", ios::out);
			break;
		case 2:
			log_file.open("Airman_normal.txt", ios::out);
			break;
		default:
			break;
		}
	}
	else {							// inf
		switch (song_index) {
		case 0:
			log_file.open("Luv_Letter_inf.txt", ios::out);
			break;
		case 1:
			log_file.open("Flower_Dance_inf.txt", ios::out);
			break;
		case 2:
			log_file.open("Airman_inf.txt", ios::out);
			break;
		default:
			break;
		}
	}
	log_file.seekg(0, ios::beg);

	cur_highscore.push(new_score);
	cur_highscore.pop();

	for (int i = 0; i < 10; i++) {
		tmp[i] = cur_highscore.top();
		cur_highscore.pop();
	}
	for (int i = 0; i < 10; i++) {
		line = to_string(tmp[9 - i]);
		new_high_score.append(line);
		new_high_score.append("\n");
	}

	log_file.write(new_high_score.c_str(), new_high_score.size());
	log_file.close();
}
