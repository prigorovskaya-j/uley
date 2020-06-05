#include <iostream>
#include "Cleaner.h"


Cleaner::Cleaner(Hive* hive) {};
Cleaner::~Cleaner() {
	cout << "destr clean";
};
void Cleaner:: eat_akt() {
	if (obj_hive.getMed() > 0 && sitost > 0 && sitost <= 25) {
		obj_hive.editMed(-0.3);	 //Hive::med-=0.3;
		sitost += 0.3;
		drink -= 0.2;
		cout << "cleaner: sitost +0.3; med -0.3, drink -0.2" << endl;
		cout << "sitost" << sitost << endl;
		cout << "med:" << obj_hive.getMed();
	}
	else {
		cout << "sitost= " << sitost << endl;
		cout << "med" << obj_hive.getMed();
	};
}; 
void Cleaner::die() {
	this->~Cleaner();
	cout << "DIE CLEANER" << endl;
};
void Cleaner::cleaner_up() {

	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else
		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getGraz() << endl;
			if (obj_hive.getMed() <= 0 || obj_hive.getWater() <= 0) {
				die();
			};
			if (obj_hive.getGraz() > 0) { //Hive::graz!=0
				if (sitost > 0 && drink > 0 && energy > 6 && obj_hive.getMed() > 0) {
					obj_hive.editGraz(-1);	//Hive::graz--;
					createWax();
					sitost -= 0.3;
					drink -= 0.2;
					energy -= 6;

					cout << "cleaner: graz -1; sitost -0.3; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
					cout << "sitost" << sitost << endl;

				}
				if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
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
					sitost -= 0.3;
					energy -= 6;
					createWax();
					cout << "cleaner: sitost -0.3; energy -6" << endl;
				}
				else if (energy < 110 && sitost>0 && drink > 0 && obj_hive.getMed() > 0 && obj_hive.getWater() > 0) {
					otdih();
					sitost -= 0.2;
					drink -= 0.2;
					createWax();
					cout << "cleaner: sitost -0.2; drink -0.2" << endl;
					cout << "sitost" << sitost << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink <= 0 || sitost <= 0 || energy <= 0) {
					die();
				};
			};
		};
};

void Cleaner::clean_wax() {

	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else
		for (int i = 0; i < 60; i += 15) {
			cout << "Vosk: " << obj_hive.getVosk() << endl;
			cout << "Wax: " << wax << endl;
			if (obj_hive.getMed() <= 0 || obj_hive.getWater() <= 0) {
				die();
			};
			if (wax > 0) { //Hive::graz!=0
				if (sitost > 0 && drink > 0 && energy > 6 && obj_hive.getMed() > 0) {
					obj_hive.editVosk(0.5);	//Hive::graz--;
					wax -= 0.5;
					sitost -= 0.3;
					drink -= 0.2;
					energy -= 6;
					createWax();
					cout << "cleaner: vosk +0.5; wax -0.5; sitost -0.3; drink -0.2; energy -6" << endl;
					cout << "energy: " << energy << endl;
					cout << "drink: " << drink << endl;
					cout << "sitost: " << sitost << endl;
					cout << "wax: " << wax << endl;
					cout << "vosk:" << obj_hive.getVosk() << endl;

				}
				if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
					eat_akt();
					createWax();
					drink -= 0.2;
					energy -= 6;
					cout << "cleaner: drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink > 0 && drink < 25 && obj_hive.getWater()>0 && energy > 0 && sitost > 0) {
					drinking();
					createWax();
					sitost -= 0.3;
					energy -= 6;
					cout << "cleaner: sitost -0.3; energy -6" << endl;
				}
				else if (energy > 0 && energy < 110 && sitost>0 && drink > 0) {
					otdih();
					createWax();
					sitost -= 0.2;
					drink -= 0.2;
					cout << "cleaner: sitost -0.2; drink -0.2" << endl;
					cout << "sitost" << sitost << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink <= 0 || sitost <= 0 || energy <= 0) {
					die();
				};
			};
		};
};

void Cleaner::Test()
{
	cout << obj_hive.getGraz() << endl;
};

