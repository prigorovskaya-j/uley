#include <iostream>
#include "Queen.h"
Queen::Queen(Hive* hive) {};
Queen::~Queen() {
	cout << "destr Queen";
}; 
void Queen::eat_akt() {
	sitost += 0.6;
	cout << "sitosk +0.6" << endl;
	obj_hive.editMed(-0.6);
	cout << "med: " << obj_hive.getMed();
};
void Queen::die() {
	this->~Queen();
	cout << "DIE Quuen" << endl;
};
void Queen::CreateBees() {
	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else
		if (sitost > 0 && drink > 0 && energy > 0) {
			for (int i = 0; i < 7; i++) {

			}
			sitost -= 1;
			cout << "sitost -1: " << sitost << endl;
			drink -= 0.5;
			cout << "drink -0.5: " << drink << endl;
			energy -= 10;
			cout << "energy -10: " << energy << endl;
		}
};
void Queen::QueenLife() {
	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
		sitost += 0.6;
		obj_hive.editMed(-0.6);
		cout << "sitost +0.6: " << sitost << "; " << "med: " << obj_hive.getMed() << ";" << endl;
		drink -= 0.2;
		energy -= 6;
		cout << "drink -0.2: " << drink << "; " << "energy -6: " << energy << ";" << endl;
	}
	else if (sitost > 0 && energy > 0 && drink > 0 && drink < 25 && obj_hive.getWater()>0) {
		drinking();
	}
	else if (sitost > 0 && drink > 0 && energy > 0 && energy < 110) {
		otdih();
	};
};