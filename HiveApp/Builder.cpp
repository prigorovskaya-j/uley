#include <iostream>
#include "Builder.h"

Builder::Builder(Hive* hive) {};
Builder::~Builder() {
	cout << "destr builder";
};
void Builder::eat_akt() {
	sitost += 0.6;
	cout << "sitosk +0.6" << endl;
	obj_hive.editMed(-0.6);
	cout << "med: " << obj_hive.getMed();
};
void Builder::die() {
	this->~Builder();
	cout << "DIE BUILDER" << endl;
};
void Builder::build() {
	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else
		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getNectar() << endl;
			if (obj_hive.getMed() <= 0 || obj_hive.getWater() <= 0) {
				die();
			}
			if (obj_hive.getNectar() >= 0) {
				cout << "builder build med" << endl;
				if (sitost > 0 && drink > 0 && energy > 0 && obj_hive.getMed() > 0 && obj_hive.getNectar() > 0) {
					obj_hive.editNectar(-1);	//Hive::graz--;
					obj_hive.editMed(0.7);
					createWax();
					sitost -= 0.6;
					drink -= 0.2;
					energy -= 6;
					cout << "builder: " << endl;
					cout << "nectar -1; med +0.7; sitost -0.6; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
					cout << "sitost" << sitost << endl;

				}
				else {
					createWax();
					cout << "nectar =" << obj_hive.getNectar() << endl;
					cout << "med = " << obj_hive.getMed() << endl;
					cout << "energy=" << energy << endl;
					cout << "drink=" << drink << endl;
					cout << "sitost=" << sitost << endl;
				};
			};
			if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
				cout << "build eat" << endl;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: drink -0.2; energy -6" << endl;
				eat_akt();
				createWax();
			}
			else if (sitost > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
				cout << "build drink" << endl;
				sitost -= 0.6;
				energy -= 6;
				cout << "builder:  sitost -0.6 ; energy -6" << endl;
				drinking();
				createWax();
			}
			else if (sitost > 0 && drink > 0 && energy > 0 && energy < 110) {
				cout << "builder otdih" << endl;
				sitost -= 0.6;
				drink -= 0.2;
				cout << "builder:  sitost -0.6; drink -0.2" << endl;
				otdih();
				createWax();
			}
			else if (drink <= 0 || sitost <= 0 || energy <= 0) {
				cout << "Builder die" << endl;
				die();
			};
		};

};
void Builder::build_soty() {
	if (sitost <= 0 || drink <= 0 || energy <= 0) {
		die();
	}
	else
		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getVosk() << endl;
			if (obj_hive.getMed() <= 0 || obj_hive.getWater() <= 0) {
				die();
			}
			if (obj_hive.getVosk() >= 0) {
				cout << "builder build soty" << endl;
				if (sitost > 0 && drink > 0 && energy > 0 && obj_hive.getVosk() > 0) {
					obj_hive.editVosk(-1);	//Hive::graz--;
					obj_hive.editSoty(0.7);
					createWax();
					sitost -= 0.6;
					drink -= 0.2;
					energy -= 6;
					cout << "builder: " << endl;
					cout << "vosk -1; soty +0.7; sitost -0.6; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink: " << drink << endl;
					cout << "sitost: " << sitost << endl;
					cout << "vosk: " << obj_hive.getVosk() << endl;
					cout << "soty: " << obj_hive.getSoty() << endl;

				}
				else {
					createWax();
					cout << "nectar =" << obj_hive.getNectar() << endl;
					cout << "med = " << obj_hive.getMed() << endl;
					cout << "energy=" << energy << endl;
					cout << "drink=" << drink << endl;
					cout << "sitost=" << sitost << endl;
				};
			};
			if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
				cout << "build eat" << endl;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: drink -0.2; energy -6" << endl;
				eat_akt();
				createWax();
			}
			else if (sitost > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
				cout << "build drink" << endl;
				sitost -= 0.6;
				energy -= 6;
				cout << "builder:  sitost -0.6 ; energy -6" << endl;
				drinking();
				createWax();
			}
			else if (sitost > 0 && drink > 0 && energy > 0 && energy < 110) {
				cout << "builder otdih" << endl;
				sitost -= 0.6;
				drink -= 0.2;
				cout << "builder:  sitost -0.6; drink -0.2" << endl;
				otdih();
				createWax();
			}
			else if (drink <= 0 || sitost <= 0 || energy <= 0) {
				cout << "Builder die" << endl;
				die();
			};
		};
};