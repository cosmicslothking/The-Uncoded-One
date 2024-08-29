#include "Entity.h"
#include <random>
#include "GameMode.h"
#include "ItemMenu.h"

Entity::Entity(string Name, eParty partyChoice, int maxEntityHealth, const shared_ptr<ItemMenu>& entityItemMenu)
{
	name = Name;
	party = partyChoice;
	totalDamage = 0;
	action = DONOTHING;
	targetName = "";
	maxHealth = maxEntityHealth;
	currentHealth = maxEntityHealth;
	itemMenu = entityItemMenu;
}

void Entity::EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity)
{
	if(gameMode == PVP)
	{
		cout << "1 - Do Nothing\n";
		cout << "2 - Standard Attack (BONE CRUNCH)\n";
		cout << "3 - Use Healing Potion\n";
		cout << "What would you like to do?\n";
		itemMenu->ActionToPerform(currentEntity);
		BaseAttacks();
	}
	else
	{
		itemMenu->ComputerActions(currentEntity);
		BaseAttacks();
	}
}

void Entity::PickTarget(vector<shared_ptr<Entity>> &entityPassed)
{
	clearTarget();

	while(target == NULL)
	{
		int randomTarget = randomNumGen(0, static_cast<int>(entityPassed.size()) - 1);

		while(entityPassed[randomTarget] == NULL)
		{
			randomTarget = randomNumGen(0, static_cast<int>(entityPassed.size()) - 1);
		}
				
		if(entityPassed[randomTarget]->getCurrentParty() != getCurrentParty() && entityPassed[randomTarget]->currentHealth >= 0)
		{
			setTarget(entityPassed[randomTarget]);
			setTargetName(entityPassed[randomTarget]);
		}
	}
}

void Entity::setHealAmount(int value)
{
	currentHealth += value;

	if(currentHealth >= maxHealth)
	{
		currentHealth = maxHealth;
	}
}

void Entity::BaseAttacks()
{
	setTotalDamage(0);

	switch(getActionEnum())
	{
	case DONOTHING:
		setActionName("NOTHING");
		break;
	case BASE_ATTACK:
		setActionName("BONE CRUNCH");
		setTotalDamage(randomNumGen(0, 1));
		target->TakeDamage(getDamageAmount());
		break;
	}
}

void Entity::TakeDamage(int damage)
{
	currentHealth -= damage;

	if(currentHealth < 0)
	{
		currentHealth = 0;
	}
}

void Entity::clearTarget()
{
	target = nullptr;
	targetName = "";
}

int Entity::randomNumGen(int min, int max)
{
	uniform_int_distribution<int> distrib(min, max);
	random_device rd;
	mt19937 gen(rd());

	return distrib(gen);
}

