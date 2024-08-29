#pragma once
using namespace std;
#include <string>

class Item
{
private:
    string name;
    string description;
    int healAmount;
    
public:
    Item(string nameInit, string descInit, int healAmountInit);

    int getHealAmount() { return healAmount; }
};
