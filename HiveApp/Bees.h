#pragma once
#include <vector>
#include "Hive.h"

class Bees
{
protected:
	int age;
	double wax;
	double sitost;
	int energy;
	double drink;
	Hive& obj_hive;
	vector<Bees> vec;
public:
	Bees(Hive* hive);
	~Bees();
	vector<Bees>::iterator ITER;
	void createWax();
	//void editVector();
	void otdih();
	void drinking();
	virtual void eat_akt() = 0;
	virtual void die() = 0;
};