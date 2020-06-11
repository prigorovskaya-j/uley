#include <iostream>
#include "Queen.h"

Queen::Queen(Hive* hive) {};
Queen::~Queen() {
	cout << "destr Queen";
}; 
void Queen::eat_akt() {
	fullness += 0.6;
	cout << "fullness +0.6" << endl;
	obj_hive.editHoney(-0.6);
	cout << "honey: " << obj_hive.getHoney();
};
void Queen::die() {
	this->~Queen();
	cout << "DIE Quuen" << endl;
};
void Queen::CreateBees() {
		if (fullness > 0 && drink > 0 && energy > 0) {
			for (int i = 0; i < 7; i++) {

			}
			fullness -= 1;
			cout << "fullness -1: " << fullness << endl;
			drink -= 0.5;
			cout << "drink -0.5: " << drink << endl;
			energy -= 10;
			cout << "energy -10: " << energy << endl;
		}
};
void Queen::QueenLife() {

	 if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
		fullness += 0.6;
		obj_hive.editHoney(-0.6);
		cout << "fullness +0.6: " << fullness << "; " << "honey: " << obj_hive.getHoney() << ";" << endl;
		drink -= 0.2;
		energy -= 6;
		cout << "drink -0.2: " << drink << "; " << "energy -6: " << energy << ";" << endl;
	}
	else if (fullness > 0 && energy > 0 && drink > 0 && drink < 25 && obj_hive.getWater()>0) {
		drinking();
	}
	else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
		otdih();
	};
};