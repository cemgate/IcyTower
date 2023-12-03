#pragma once


class ScoreManager
{
private:
	int _score = 0;
	int _combo = 0;
	int _lastPlatformStanding = 0;
	bool _isComboNow = false;

public:

	void rewardScore(int platformStanding, int howManyPlatforms,bool isPlayerOnGroundd);
	int getScore();
	bool getComboStatus();
	
};

