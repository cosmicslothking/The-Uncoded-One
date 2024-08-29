#include "CombatTracker.h"
#include <iostream>
using namespace std;

CombatTracker::CombatTracker(vector<shared_ptr<Entity>>& currentVector, int &roundOverNum)
{
	CalculatePartySize(currentVector);
	roundOverCounter = roundOverNum;
}

void CombatTracker::DisplayBattle(shared_ptr<Entity> &currentEntity, vector<shared_ptr<Entity>> &currentVector)
{
	DisplayGameStatus(currentVector, currentEntity);

	currentEntity->PickTarget(currentVector);

	cout << "it is " << currentEntity->getName() << "'s turn..." << "\n";

	currentEntity->EntityAction(gameMode.getGameMode(), currentEntity);

	if (currentEntity->getActionEnum() == DONOTHING)
	{
		cout << currentEntity->getName() << " did " << currentEntity->getActionName() << "." << "\n";
	}
	else if(currentEntity->getActionEnum() == HEALING)
	{
		cout << currentEntity->getName() << " Used a healing potion" << "\n";
	}
	else
	{
		cout << currentEntity->getName() << " used " << currentEntity->getActionName() << " on " << currentEntity->
			getTargetName() << "\n";
		cout << currentEntity->getActionName() << " dealt " << currentEntity->getDamageAmount() << " damage to " <<
			currentEntity->getTargetName() << "\n";
		cout << currentEntity->getTargetName() << " is now at " << currentEntity->getTarget()->getCurrentHealth() << "/"
			<< currentEntity->getTarget()->getMaxHealth() << " HP." << "\n";
	}

	RemoveDeadEntity(currentEntity, currentVector);

	cout << "\n";
	cout << flush;

	//this_thread::sleep_for(800ms);
}

void CombatTracker::RemoveDeadEntity(shared_ptr<Entity> &currentEntity, vector<shared_ptr<Entity>> &currentVector)
{
	int currentTargetHealth = currentEntity->getTarget()->getCurrentHealth();
	string currentTargetName = currentEntity->getTargetName();

	if(currentTargetHealth <= 0)
	{
		cout << currentTargetName << " has died!\n";

		CheckBossDeathEncounter(currentEntity);

		RemoveEntitiesFromPartyVector(currentEntity, currentVector);
	}
	
	for (int i = 0; i < currentVector.size(); i++)
	{
		currentVector[i]->clearTarget();
	}
}

bool CombatTracker::IsRoundOver(int &roundNum, int &currentRound)
{
	if(heroesPartySize == 0 || enemyPartySize == 0)
	{
		CheckPartyWinner();
		if (roundNum == currentRound)
		{
			roundNum++;
		}
		
		return true;
	}

	return false;
}

void CombatTracker::CheckPartyWinner() const
{
	if (heroesPartySize <= 0)
	{
		cout << '\n';
		cout << "The Heroes have lost, The Uncoded Ones forces have prevailed! \n";
		exit(666);
 	}
}

void CombatTracker::CalculatePartySize(vector<shared_ptr<Entity>> &currentVector)
{
	for (int i = 0; i < currentVector.size(); i++)
	{
		if(currentVector[i]->getCurrentParty() == Heroes)
		{
			heroesPartySize++;
		}
		else
		{
			enemyPartySize++;
		}
	}
}

void CombatTracker::DisplayGameStatus(vector<shared_ptr<Entity>> &currentVector, shared_ptr<Entity> &currentEntity)
{
	vector<shared_ptr<Entity>> heroVector;
	vector<shared_ptr<Entity>> enemyVector;

	for (int i = 0; i < currentVector.size(); i++)
	{
		if(currentVector[i]->getCurrentParty() == Heroes)
		{
			heroVector.push_back(currentVector[i]);
		}
		else
		{
			enemyVector.push_back(currentVector[i]);
		}
	}
	
	cout << "===================================================================== BATTLE =====================================================================\n";
	for (auto& i : heroVector)
	{
		cout << MarkCurrentTurn(currentEntity, i) << " ( " << i->getCurrentHealth() << "/" << i->getMaxHealth() << " )" << "\n";
	}
	cout << "----------------------------------------------------------------------- vs -----------------------------------------------------------------------\n";
	
	for (auto& i : enemyVector)
	{
		cout << MarkCurrentTurn(currentEntity, i) << " (" << i->getCurrentHealth() << "/" << i->getMaxHealth() << ")" << "\n";
	}
	cout << "==================================================================================================================================================\n\n";
}

string CombatTracker::MarkCurrentTurn(shared_ptr<Entity> &currentEntity, shared_ptr<Entity> &currentVector)
{
	if(currentVector == currentEntity)
	{
		return currentVector->getName() + "*";
	}

	return currentVector->getName();
}

void CombatTracker::RemoveEntitiesFromPartyVector(shared_ptr<Entity>& currentEntity, vector<shared_ptr<Entity>>& currentVector)
{
	eParty currentTargetParty = currentEntity->getTarget()->getCurrentParty();

	if(currentTargetParty == Heroes)
	{
		heroesPartySize--;
		for(int i = 0; i < currentVector.size(); i++)
		{
			if(currentVector[i]->getCurrentHealth() <= 0)
			{
				currentVector.erase(currentVector.begin() + i);
			}
		}
	}
	else
	{
		enemyPartySize--;
		for(int i = 0; i < currentVector.size(); i++)
		{
			if(currentVector[i]->getCurrentHealth() <= 0)
			{
				currentVector.erase(currentVector.begin() + i);
			}
		}
	}
}

void CombatTracker::CheckBossDeathEncounter(shared_ptr<Entity> &currentEntity)
{
	if(currentEntity->getTarget()->getName() == "The Uncoded One" && currentEntity->getTarget()->getCurrentHealth() == 0)
	{
		cout << "\nYou have won... For NOW!!!! MUAHAHAHAHAHAHA\n";
		exit(666);
	}
}
