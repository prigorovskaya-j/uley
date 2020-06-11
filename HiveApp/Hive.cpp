#include <iostream>
#include "Hive.h"

Hive::Hive()
{
	vosk = 0;
	mud = 0;
	honey = 0;
	water = 0;
	nectar = 0;
	honeycombs = 0;
	cout << "const_hive" << endl;
};

Hive::~Hive() {
	cout << "destr_hive" << endl;
	delete[] arr_hive;
};

void Hive::foul() { //загр€зн€тьс€
	mud += 1.5;
	cout << "mud=" << mud << endl;
};

void Hive:: initialCondtion() {
	/*cout << "enter max size: " << endl;
	cin >> size; */
	cout << "¬ведите начальное количество меда" << endl;
	cin >> honey;
	cout << "¬ведите начальное количество воды" << endl;
	cin >> water;
	cout << "¬ременно введите начальное количество нектара" << endl;
	cin >> nectar;
};