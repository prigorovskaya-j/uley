#pragma once

#include "Bees.h"

class Cleaner : Bees
{
public:    
    Cleaner(Hive* hive); 
    ~Cleaner();
    void eat_akt();
    void die();
    void cleaner_up();
    void Test();
    void clean_wax();
};