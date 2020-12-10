#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

class GamePlay {
private:
	GameTable* gt;
public:
	GamePlay();
	GamePlay(int n);
	~GamePlay();
};

void StartGame(int music, int mode);
