#pragma once
#include "Entity.h"
#include <chrono>
#include <vector>

#include "GameMode.h"

class CombatTracker
{
public:
	CombatTracker(vector<shared_ptr<Entity>>& currentVector, int &roundOverNum);
	void DisplayBattle(shared_ptr<Entity> &currentEntity, vector<shared_ptr<Entity>> &currentVector);
	void RemoveDeadEntity(shared_ptr<Entity> &currentEntity, vector<shared_ptr<Entity>> &currentVector);
	bool IsRoundOver(int &roundNum, int &currentRound);
	void CheckPartyWinner() const;
	void CalculatePartySize(vector<shared_ptr<Entity>> &currentVector);

	int getHeroPartySize() const {return heroesPartySize; }
	int getEnemyPartySize() const { return enemyPartySize; }
	
	int roundOverCounter {0};

private:
	int heroesPartySize {0};
	int enemyPartySize {0};
	
	GameMode gameMode;

	static void DisplayGameStatus(vector<shared_ptr<Entity>> &currentVector, shared_ptr<Entity> &currentEntity);
	static string MarkCurrentTurn(shared_ptr<Entity> &currentEntity, shared_ptr<Entity> &currentVector);

	void RemoveEntitiesFromPartyVector(shared_ptr<Entity> &currentEntity, vector<shared_ptr<Entity>> &currentVector);

	static void CheckBossDeathEncounter(shared_ptr<Entity> &currentEntity);
};

