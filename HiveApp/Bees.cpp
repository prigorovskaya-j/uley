#include<iostream>
#include<vector>
#include "Bees.h"

Bees::Bees(Hive* hive) {
	sitost = 25;
	energy = 110;
	drink = 25;
	wax = 0;
	age = 0;
	cout << "const_bees" << endl;
};
void Bees::createWax() {
	if (energy > 0 && sitost > 0 && drink > 0) {
		wax += 0.5;
		cout << "wax: " << wax << endl;
	};
};
/*void Bees::editVector() {
		do {
			getline(cin, buffer);
			if (buffer.size() > 0) {
				// Добавление элемента в конец вектора
				vec.push_back(buffer);
			}
		} while (buffer != "");
		unsigned int vector_size = vec.size();
		//vec.resize(7,Bees obj_bees); - добавит
};*/
void Bees::otdih() {

	if (energy > 0 && energy < 110) {
		energy += 15;
		cout << "energy+15: " << energy << endl;
	}
	else  cout << "energy: " << energy << endl;
};
void Bees::drinking() {
	if (drink > 0 && drink <= 25 && obj_hive.getWater() > 0) {
		drink += 0.2;
		obj_hive.editWater(-0.2);
		cout << "drink +0.2 :" << drink << endl;
		cout << "water: " << obj_hive.getWater() << endl;
	}
	else cout << "drink:" << drink << endl;

};
