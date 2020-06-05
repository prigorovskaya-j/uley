#include <iostream>
#include "Hive.h"

Hive::Hive()
{
	vosk = 0;
	graz = 0;
	med = 0;
	water = 0;
	nectar = 0;
	soty = 0;
	cout << "const_hive" << endl;
};

Hive::~Hive() {
	cout << "destr_hive" << endl;
	delete[] arr_hive;
};

void Hive::foul() { //загр€зн€тьс€
	graz += 1.5;
	cout << "graz=" << graz << endl;
};

void Hive:: initial_condtion() {
	/*cout << "enter max size: " << endl;
	cin >> size; */
	cout << "¬ведите начальное количество меда" << endl;
	cin >> med;
	cout << "¬ведите начальное количество воды" << endl;
	cin >> water;
	cout << "¬ременно введите начальное количество нектара" << endl;
	cin >> nectar;
};