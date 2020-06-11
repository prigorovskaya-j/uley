#pragma once
#include <vector>
#include "Hive.h"

using namespace std;

class Bees: public Hive{
protected:
	int age;
	double wax;
	double fullness;
	int energy;
	double drink;
	Hive& obj_hive;
	vector<Bees> vec;
public:
	Bees(Hive* hive);
	~Bees();
	vector<Bees>::iterator ITER;
	void createWax();
	void checkingDeath();
	//void editVector();
	void otdih();
	void drinking();
	virtual void eat_akt() = 0;
	virtual void die() = 0;
};