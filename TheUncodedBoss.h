#pragma once
#include "Entity.h"
#include "ItemMenu.h"

class ItemMenu;

class TheUncodedBoss : public Entity
{
public:
    TheUncodedBoss(const string Name, eParty partyChoice, int maxEntityHealth, const shared_ptr<ItemMenu>& entityItemMenu) : Entity(Name, partyChoice, maxEntityHealth, entityItemMenu) {}
    void EntityAction(eGameMode gameMode, shared_ptr<Entity> &currentEntity) override;
    void BaseAttacks() override;
    void TakeDamage(int damage) override;
};
