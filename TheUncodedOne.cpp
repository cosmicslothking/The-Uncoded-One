#include <iostream>
#include <vector>
#include "Entity.h"
#include "eParty.h"
#include "CombatTracker.h"
#include "GameMode.h"
#include "Inventory.h"
#include "Player.h"
#include "random"
#include "TheUncodedBoss.h"
using namespace std;

int main()
{
	int roundTracker {1};
	int firstRound {0};
	int secondRound {0};
	int thirdRound {0};
	
	string trueProgrammerName;
	cout << "What is your name Ture Programmer?!\n";

	//cin >> trueProgrammerName;

	GameMode::setGameMode(PVE);
	GameMode::GameModeSelection();

	shared_ptr<ItemMenu> itemMenu = make_unique<ItemMenu>();
	
	shared_ptr<Player> playerOne = make_shared<Player>("Rico", Heroes, 25, itemMenu);
	shared_ptr<Player> playerTwo = make_shared<Player>("Vin Fletcher", Heroes, 25, itemMenu);

	shared_ptr<Inventory> heroesInventory = make_shared<Inventory>(3);
	shared_ptr<Inventory> enemyInventoryOne = make_shared<Inventory>(1);
	shared_ptr<Inventory> enemyInventoryTwo = make_shared<Inventory>(1);
	shared_ptr<Inventory> enemyInventoryThree = make_shared<Inventory>(1);

	vector<shared_ptr<Entity>> firstEncounter;
	firstEncounter.push_back(playerOne);
	firstEncounter.push_back(playerTwo);
	firstEncounter.push_back(make_shared<Entity>(Entity("Skeleton One", Enemy, 5, itemMenu)));
	firstEncounter.push_back(make_shared<Entity>(Entity("Skeleton Two", Enemy, 5, itemMenu)));
	firstEncounter.push_back(make_shared<Entity>(Entity("Skeleton Three", Enemy, 5, itemMenu)));

	vector<shared_ptr<Entity>> secondEncounter;
	secondEncounter.push_back(playerOne);
	secondEncounter.push_back(playerTwo);
	secondEncounter.push_back(make_shared<Entity>(Entity("Dark Skeleton One", Enemy, 5, itemMenu)));
	secondEncounter.push_back(make_shared<Entity>(Entity("Dark Skeleton Two", Enemy, 5, itemMenu)));
	secondEncounter.push_back(make_shared<Entity>(Entity("Dark Skeleton Three", Enemy, 5, itemMenu)));

	vector<shared_ptr<Entity>> thirdEncounter;
	thirdEncounter.push_back(playerOne);
	thirdEncounter.push_back(playerTwo);
	thirdEncounter.push_back(make_shared<Entity>(Entity("Blood Skeleton One", Enemy, 5, itemMenu)));
	thirdEncounter.push_back(make_shared<Entity>(Entity("Blood Skeleton Two", Enemy, 5, itemMenu)));
	thirdEncounter.push_back(make_shared<TheUncodedBoss>(TheUncodedBoss("The Uncoded One", Enemy, 15, itemMenu)));

	unique_ptr<CombatTracker> combatTrackerOne = make_unique<CombatTracker>(firstEncounter, roundTracker);
	unique_ptr<CombatTracker> combatTrackerTwo = make_unique<CombatTracker>(secondEncounter, roundTracker);
	unique_ptr<CombatTracker> combatTrackerThree = make_unique<CombatTracker>(thirdEncounter, roundTracker);

	cout << "First encounter" << "\n\n";
	
	while(roundTracker <= 3)
	{
		switch(roundTracker)
		{
			case 1:
				firstRound = 1;
				for (int i = 0; i < firstEncounter.size(); i++)
				{
					if(!combatTrackerOne->IsRoundOver(roundTracker, firstRound))
					{
						if(firstEncounter[i]->getCurrentParty() == Heroes)
						{
							itemMenu->setInventory(heroesInventory);
						}
						else
						{
							itemMenu->setInventory(enemyInventoryOne);
						}
						combatTrackerOne->DisplayBattle(firstEncounter[i], firstEncounter);
					}
				}
				break;
			case 2:
				secondRound = 2;
				for (int i = 0; i < secondEncounter.size(); i++)
				{
					if(!combatTrackerTwo->IsRoundOver(roundTracker, secondRound))
					{
						if(secondEncounter[i]->getCurrentParty() == Heroes)
						{
							itemMenu->setInventory(heroesInventory);
						}
						else
						{
							itemMenu->setInventory(enemyInventoryTwo);
						}
						combatTrackerTwo->DisplayBattle(secondEncounter[i], secondEncounter);
					}
				}
				break;
			case 3:
				thirdRound = 3;
				for (int i = 0; i < thirdEncounter.size(); i++)
				{
					if(!combatTrackerThree->IsRoundOver(roundTracker, thirdRound))
					{
						if(thirdEncounter[i]->getCurrentParty() == Heroes)
						{
							itemMenu->setInventory(heroesInventory);
						}
						else
						{
							itemMenu->setInventory(enemyInventoryThree);
						}
						combatTrackerThree->DisplayBattle(thirdEncounter[i], thirdEncounter);
					}
				}	
				break;
		}
	}

	return 0;
}