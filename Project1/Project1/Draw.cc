#include <iostream>
#include <Windows.h>
#include "Draw.h"

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
	system("mode con:cols=50 lines=20");
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
	gotoxy(10, 2);
	cout << "******************************";
	gotoxy(10, 3);
	cout << "*         Rythm Game         *";
	gotoxy(10, 4);
	cout << "******************************";
	gotoxy(20, 8);
	cout << "GameStart";
	gotoxy(20, 9);
	cout << "GameInfo";
	gotoxy(20, 10);
	cout << "Quit" << endl;
}

void DrawInfo()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 3);
	cout << "******************************";
	gotoxy(10, 4);
	cout << "        Developed BY          ";
	gotoxy(10, 5);
	cout << "        Choi In Tae           ";
	gotoxy(10, 6);
	cout << "        Kim Jin Seok          ";
	gotoxy(10, 7);
	cout << "        Jeong Yeun Keun       ";
	gotoxy(10, 8);
	cout << "******************************";
	system("pause>null");
}

void DrawStartMenu()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 2);
	cout << "******************************";
	gotoxy(10, 3);
	cout << "*      Select Game Mode      *";
	gotoxy(10, 4);
	cout << "******************************";
	gotoxy(20, 8);
	cout << "Normal Mode";
	gotoxy(20, 9);
	cout << "Infinity Mode";
	gotoxy(20, 10);
	cout << "GO BACK" << endl;
}

void DrawMusicMenu()
{
	system("cls");
	CursorView(false);
	gotoxy(10, 2);
	cout << "******************************";
	gotoxy(10, 3);
	cout << "*        Select Music        *";
	gotoxy(10, 4);
	cout << "******************************";
	gotoxy(20, 8);
	cout << "Luv Letter";
	gotoxy(20, 9);
	cout << "Flower Dance";
	gotoxy(20, 10);
	cout << "I can't Beat Airman";
	gotoxy(20, 11);
	cout << "GO BACK" << endl;
}

/*void DrawGameover() 
{

}*/

void DrawUserCursor(int num_menu, int& y)
{
	if (y <= 0) y = 0;
	else if (y >= num_menu - 1) y = num_menu - 1;
	gotoxy(18, 8 + y);
	cout << ">";
}

bool Quit()
{
	system("cls");
	return TRUE;
}
