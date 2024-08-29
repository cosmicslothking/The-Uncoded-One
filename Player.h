#pragma once
#include "Entity.h"
using namespace std;
#include <iostream>

class Entity;
class ItemMenu;

class Player : public Entity
{
public:
    Player(const string Name, eParty partyChoice, int maxEntityHealth, const shared_ptr<ItemMenu>& entityItemMenu) : Entity(Name, partyChoice, maxEntityHealth, entityItemMenu){}
    
    void EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity) override;

    void BaseAttacks() override;
};

