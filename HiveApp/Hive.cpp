#include <iostream>
#include "Hive.h"

Hive::Hive()
{
    pollutionValue = 0;
    honeyAmount = 0;
    waterAmount = 0;
};

void Hive::Pollute()
{
    pollutionValue += 1.5;
};

void Hive::Initialise()
{

    cout << "Enter initial honey amount:" << endl;
    cin >> honeyAmount;
    cout << "Enter initial water amount:" << endl;
    cin >> waterAmount;
}