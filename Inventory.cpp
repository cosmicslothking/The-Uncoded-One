#include "Inventory.h"

#include "Entity.h"

Inventory::Inventory(int consumableCapacity)
{
    for (int i = 0; i < consumableCapacity; i++)
    {
        consumables.push_back(make_unique<Item>("Health Potion", "A healing potion that recovered 10 points of health", 10));
    }
}

void Inventory::UseItemFromInventory(shared_ptr<Entity> &owner)
{
    if(!consumables.empty())
    {
        owner->setHealAmount(consumables[0]->getHealAmount());
        consumables.erase(consumables.begin());
    }
}
