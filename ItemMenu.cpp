#include "ItemMenu.h"
#include <random>
#include "Entity.h"
#include "Inventory.h"

void ItemMenu::ActionToPerform(shared_ptr<Entity> &owner)
{
    int input;
    cin >> input;

    PickAction(input, owner);
}

void ItemMenu::ComputerActions(shared_ptr<Entity> &owner)
{
    PickAction(RandomNumGen(1,2), owner);
}

void ItemMenu::PickAction(int action, shared_ptr<Entity> &owner)
{
    switch (action)
    {
    case 1:
        owner->setActionEnum(DONOTHING);
        break;
    case 2:
        owner->setActionEnum(BASE_ATTACK);
        break;
    case 3:
        owner->setActionEnum(HEALING);
        entityInventory->UseItemFromInventory(owner);
        cout << entityInventory->getInventorySize() << " Potions left\n";
        break;
    case 4:
        break;
    }
}

void ItemMenu::DeterminePotionUse(shared_ptr<Entity> &owner)
{
    if(entityInventory != nullptr)
    {
        if(RandomNumGen(0, 100) <= 25)
        {
            PickAction(3, owner);
        }
    }
}

int ItemMenu::RandomNumGen(int min, int max)
{
    uniform_int_distribution<int> distrib(min, max);
    random_device rd;
    mt19937 gen(rd());

    return distrib(gen);
}
