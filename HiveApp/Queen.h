#pragma once
 
#include "Bees.h"

class Queen{
public: 
	Queen(Hive* hive);
	~Queen();
	void eat_akt();
	void die();
	void CreateBees();
	void QueenLife();

};