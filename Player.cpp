#include "Player.h"
#include "eGameMode.h"
#include "GameMode.h"
#include "ItemMenu.h"

void Player::EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity)
{
     if(gameMode == PVE)
     {
          cout << "1 - Do Nothing\n";
          cout << "2 - Standard Attack (PUNCH)\n";
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

void Player::BaseAttacks()
{
     setTotalDamage(0);

     switch(getActionEnum())
     {
     case DONOTHING:
          setActionName("NOTHING");
          break;

     case BASE_ATTACK:
          setActionName("PUNCH");
          setTotalDamage(randomNumGen(0, 1));
          target->TakeDamage(getDamageAmount());
          break;
     }
}
