#include <iostream>

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