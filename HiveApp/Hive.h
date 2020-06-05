#pragma once

using namespace std;

class Hive
{
private:
    double pollutionValue;
    double honeyAmount;
    int waterAmount;
public:
    Hive();
    void Pollute();
    void Initialise();
};