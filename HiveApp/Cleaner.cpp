#include <iostream>
#include "Cleaner.h"


Cleaner::Cleaner(Hive* hive) {};
Cleaner::~Cleaner() {
	cout << "destr clean";
};
void Cleaner:: eat_akt() {
	if (obj_hive.getHoney() > 0 && fullness > 0 && fullness <= 25) {
		obj_hive.editHoney(-0.3);	 //Hive::honey-=0.3;
		fullness += 0.3;
		drink -= 0.2;
		cout << "cleaner: fullness +0.3; honey -0.3, drink -0.2" << endl;
		cout << "fullness" << fullness << endl;
		cout << "honey:" << obj_hive.getHoney();
	}
	else {
		cout << "fullness= " << fullness << endl;
		cout << "honey" << obj_hive.getHoney();
	};
}; 
void Cleaner::die() {
	this->~Cleaner();
	cout << "DIE CLEANER" << endl;
};
void Cleaner::cleanerUp() {

		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getMud() << endl;
			if (obj_hive.getMud() > 0) { //Hive::mud!=0
				if (fullness > 0 && drink > 0 && energy > 6 && obj_hive.getHoney() > 0) {
					obj_hive.editMud(-1);	//Hive::mud--;
					createWax();
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;

					cout << "cleaner: mud -1; fullness -0.3; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
					cout << "fullness" << fullness << endl;

				}
				if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
					eat_akt();
					drink -= 0.2;
					energy -= 6;
					createWax();
					cout << "cleaner: drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink < 25 && obj_hive.getWater()>0) {
					drinking();
					fullness -= 0.3;
					energy -= 6;
					createWax();
					cout << "cleaner: fullness -0.3; energy -6" << endl;
				}
				else if (energy < 110 && fullness>0 && drink > 0 && obj_hive.getHoney() > 0 && obj_hive.getWater() > 0) {
					otdih();
					fullness -= 0.2;
					drink -= 0.2;
					createWax();
					cout << "cleaner: fullness -0.2; drink -0.2" << endl;
					cout << "fullness" << fullness << endl;
					cout << "drink:" << drink << endl;
				}
			};
		};
};

void Cleaner::cleanWax() {

		for (int i = 0; i < 60; i += 15) {
			cout << "Vosk: " << obj_hive.getVosk() << endl;
			cout << "Wax: " << wax << endl;
			if (wax > 0) { //Hive::mud!=0
				if (fullness > 0 && drink > 0 && energy > 6 && obj_hive.getHoney() > 0) {
					obj_hive.editVosk(0.5);	//Hive::mud--;
					wax -= 0.5;
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;
					createWax();
					cout << "cleaner: vosk +0.5; wax -0.5; fullness -0.3; drink -0.2; energy -6" << endl;
					cout << "energy: " << energy << endl;
					cout << "drink: " << drink << endl;
					cout << "fullness: " << fullness << endl;
					cout << "wax: " << wax << endl;
					cout << "vosk:" << obj_hive.getVosk() << endl;

				}
				if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
					eat_akt();
					createWax();
					drink -= 0.2;
					energy -= 6;
					cout << "cleaner: drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink > 0 && drink < 25 && obj_hive.getWater()>0 && energy > 0 && fullness > 0) {
					drinking();
					createWax();
					fullness -= 0.3;
					energy -= 6;
					cout << "cleaner: fullness -0.3; energy -6" << endl;
				}
				else if (energy > 0 && energy < 110 && fullness>0 && drink > 0) {
					otdih();
					createWax();
					fullness -= 0.2;
					drink -= 0.2;
					cout << "cleaner: fullness -0.2; drink -0.2" << endl;
					cout << "fullness" << fullness << endl;
					cout << "drink:" << drink << endl;
				}

			};
		};
};

void Cleaner::Test()
{
	cout << obj_hive.getMud() << endl;
};

