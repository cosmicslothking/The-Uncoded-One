#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "eActions.h"
#include "eGameMode.h"
#include "eParty.h"

class ItemMenu;
using namespace std;

class Entity
{
public:
	Entity(const string Name, eParty partyChoice, int maxEntityHealth, const shared_ptr<ItemMenu>& entityItemMenu);
	virtual void EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity);

	void PickTarget(vector<shared_ptr<Entity>> &entityPassed);
	
	string getName() { return name; }
	string getActionName() { return actionName; }
	void setActionName(string value) { actionName = value; }
	
	string getTargetName() { return targetName; }
	void setTargetName(shared_ptr<Entity>& value) { targetName = value->getName(); }
	
	eActions getActionEnum() { return action; }
	void setActionEnum(eActions value) { action = value; }
	eParty getCurrentParty() { return party; }

	int getDamageAmount() { return totalDamage; }
	void setTotalDamage(int value) { totalDamage = value;}
	void setHealAmount(int value);
	
	shared_ptr<Entity> &getTarget() { return target; }
	void setTarget(shared_ptr<Entity> &value) { target = value; }

	virtual void BaseAttacks();
	virtual void TakeDamage(int damage);
	
	int getCurrentHealth() { return currentHealth; }
	int getMaxHealth() { return maxHealth; }

	void clearTarget();

	int randomNumGen(int min, int max);


protected:
	string actionName;
	eActions action;

	string name;
	string targetName;

	int maxHealth;
	int currentHealth;
	int totalDamage;

	eParty party;
	
	shared_ptr<Entity> target;
	shared_ptr<ItemMenu> itemMenu;
};

