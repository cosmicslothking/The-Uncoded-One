#pragma once
#include <memory>
#include <vector>

#include "Item.h"

class Entity;

class Inventory
{
public:
    Inventory();
    Inventory(int consumableCapacity);
    void UseItemFromInventory(shared_ptr<Entity> &owner);

    int getInventorySize() { return static_cast<int>(consumables.size()); }
    
private:
    vector<unique_ptr<Item>> consumables;
};
