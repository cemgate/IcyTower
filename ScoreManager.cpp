#include "includes.h"
#include "ScoreManager.h"

int ScoreManager::getScore()
{
	return this->_score;
}

bool ScoreManager::getComboStatus()
{
	return _isComboNow;
}

void ScoreManager::rewardScore(int platformStanding, int howManyPlatforms, bool isPlayerOnGround)
{
	int currentPlatform = platformStanding + howManyPlatforms - 20;

	if (currentPlatform - _lastPlatformStanding >= 2 && !isPlayerOnGround)
	{
		_combo += currentPlatform - _lastPlatformStanding;
		_score += 10 + _combo * 10;
		_isComboNow = true;
	}
	else if (currentPlatform - _lastPlatformStanding == 1)
	{
		_score += 10;
		_isComboNow = false;
	}

	else if (!isPlayerOnGround)
	{
		_combo = 0;
		_isComboNow = false;
	}

	_lastPlatformStanding = currentPlatform;

}
