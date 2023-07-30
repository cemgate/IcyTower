#pragma once
#include "Player.h"

const float ACCELERATION = 0.2f;
const float MAX_SPEED = 10.0f;
const float MIN_SPEED = -10.0f;
const float JUMP_ACCELERATION = 4.0f;
const float G = 0.981f;

class InputManager
{
public:
	bool leftMovement = false;
	bool rightMovement = false;
	bool jumpMovement = false;
	void checkInput();
	void inputFirstScreen();
	void inputGame(Player& player);
};

