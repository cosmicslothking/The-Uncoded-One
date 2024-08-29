#include "TheUncodedBoss.h"
#include <random>
#include "ItemMenu.h"
#include "GameMode.h"

void TheUncodedBoss::EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity)
{
    Entity::EntityAction(gameMode, currentEntity);
     
    unique_ptr<ItemMenu> itemMenu = unique_ptr<ItemMenu>();

    if(gameMode == PVP)
    {
        cout << "1 - Do Nothing\n";
        cout << "2 - Standard Attack (UNRAVELING)\n";
        cout << "What would you like to do?\n";
        itemMenu->ActionToPerform(currentEntity);

    }
    else
    {
        itemMenu->ComputerActions(currentEntity);
    }
}

void TheUncodedBoss::BaseAttacks()
{
    setTotalDamage(0);
    
    switch(getActionEnum())
    {
    case DONOTHING:
        setActionName("NOTHING");
        break;

    case BASE_ATTACK:
        setActionName("UNRAVELING");
        target->TakeDamage(randomNumGen(0, 2));
        break;
    }
}

void TheUncodedBoss::TakeDamage(int damage)
{
    currentHealth -= damage;

    if(currentHealth <= 0)
    {
        currentHealth = 0;
    }
}
