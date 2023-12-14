#pragma once
#include "Player.h"
#include "ScoreManager.h"
#include "ComboStars.h"

constexpr float ACCELERATION = 0.3f;
constexpr float MAX_SPEED = 15.0f;
constexpr float MIN_SPEED = -15.0f;
constexpr float JUMP_ACCELERATION = 20.0f;
constexpr float G = 1.981f;

class InputManager
{
public:

	bool leftMovement = false;
	bool rightMovement = false;
	bool jumpMovement = false;
	void checkInput();
	void inputFirstScreen();
	void inputGame(Player& player, ScoreManager& score, ComboStars& stars);
	void comboCondition(Player& player, ScoreManager& score, ComboStars& stars);
};

