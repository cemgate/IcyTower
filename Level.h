#pragma once

#include "Screen.h"

class Level
{
private:
	std::vector<std::unique_ptr<Screen>> objectsScreenFirst;
	std::vector<std::unique_ptr<Screen>> objecstScreenGame;
	std::vector<std::unique_ptr<Screen>> objectScreenDead;

	void loadObjectsScreenFirst();
	void loadObjectsScreenGame();
	void loadObjectsScreenFirstDead();
	
};

