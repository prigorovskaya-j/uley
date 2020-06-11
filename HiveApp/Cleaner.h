#pragma once

#include "Bees.h"

class Cleaner : public Bees
{
public:    
    Cleaner(Hive* hive); 
    ~Cleaner();
    void eat_akt();
    void die();
    void cleanerUp();
    void Test();
    void cleanWax();
};