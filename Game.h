#include <iostream>
#include <string>
#include <ctime>
#include "Menu.h"

using namespace std;

class GamePlay {
private:
	clock_t start;
	clock_t end;
	int playtime;
	GameTable* gt;
public:
	GamePlay();
	GamePlay(int n);
	~GamePlay();
	bool CheckEndMusic(clock_t start, clock_t end, int music, int check);
};

void StartGame(int music, int mode);
