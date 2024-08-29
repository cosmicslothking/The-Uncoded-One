#pragma once
#include <iostream>

using namespace std;

class Inventory;
class Item;
class Entity;

class ItemMenu
{
private:
    static int RandomNumGen(int min, int max);

protected:
    shared_ptr<Inventory> entityInventory;

public:
    void ActionToPerform(shared_ptr<Entity> &owner);
    void ComputerActions(shared_ptr<Entity> &owner);
    void PickAction(int action, shared_ptr<Entity> &owner);
    void DeterminePotionUse(shared_ptr<Entity> &owner);

    void setInventory(shared_ptr<Inventory> &value) { entityInventory = value; }
};
