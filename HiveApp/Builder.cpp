#include <iostream>
#include "Builder.h"

Builder::Builder(Hive* hive) {};
Builder::~Builder() {
	cout << "destr builder";
};
void Builder::eat_akt() {
	fullness += 0.6;
	cout << "sitosk +0.6" << endl;
	obj_hive.editHoney(-0.6);
	cout << "honey: " << obj_hive.getHoney();
};
void Builder::die() {
	this->~Builder();
	cout << "DIE BUILDER" << endl;
};
void Builder::build() {

		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getNectar() << endl;
			if (obj_hive.getNectar() >= 0) {
				cout << "builder build honey" << endl;
				if (fullness > 0 && drink > 0 && energy > 0 && obj_hive.getHoney() > 0 && obj_hive.getNectar() > 0) {
					obj_hive.editNectar(-1);	//Hive::graz--;
					obj_hive.editHoney(0.7);
					createWax();
					fullness -= 0.6;
					drink -= 0.2;
					energy -= 6;
					cout << "builder: " << endl;
					cout << "nectar -1; honey +0.7; fullness -0.6; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
					cout << "fullness" << fullness << endl;

				}
				else {
					createWax();
					cout << "nectar =" << obj_hive.getNectar() << endl;
					cout << "honey = " << obj_hive.getHoney() << endl;
					cout << "energy=" << energy << endl;
					cout << "drink=" << drink << endl;
					cout << "fullness=" << fullness << endl;
				};
			};
			if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
				cout << "build eat" << endl;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: drink -0.2; energy -6" << endl;
				eat_akt();
				createWax();
			}
			else if (fullness > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
				cout << "build drink" << endl;
				fullness -= 0.6;
				energy -= 6;
				cout << "builder:  fullness -0.6 ; energy -6" << endl;
				drinking();
				createWax();
			}
			else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
				cout << "builder otdih" << endl;
				fullness -= 0.6;
				drink -= 0.2;
				cout << "builder:  fullness -0.6; drink -0.2" << endl;
				otdih();
				createWax();
			}
		};

};
void Builder::buildHoneycombs() {
		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getVosk() << endl;
			if (obj_hive.getHoney() <= 0 || obj_hive.getWater() <= 0) {
				die();
			}
			if (obj_hive.getVosk() >= 0) {
				cout << "builder build honeycombs" << endl;
				if (fullness > 0 && drink > 0 && energy > 0 && obj_hive.getVosk() > 0) {
					obj_hive.editVosk(-1);	//Hive::graz--;
					obj_hive.editHoneycombs(0.7);
					createWax();
					fullness -= 0.6;
					drink -= 0.2;
					energy -= 6;
					cout << "builder: " << endl;
					cout << "vosk -1; honeycombs +0.7; fullness -0.6; drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink: " << drink << endl;
					cout << "fullness: " << fullness << endl;
					cout << "vosk: " << obj_hive.getVosk() << endl;
					cout << "honeycombs: " << obj_hive.getHoneycombs() << endl;

				}
				else {
					createWax();
					cout << "nectar =" << obj_hive.getNectar() << endl;
					cout << "honey = " << obj_hive.getHoney() << endl;
					cout << "energy=" << energy << endl;
					cout << "drink=" << drink << endl;
					cout << "fullness=" << fullness << endl;
				};
			};
			if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
				cout << "build eat" << endl;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: drink -0.2; energy -6" << endl;
				eat_akt();
				createWax();
			}
			else if (fullness > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
				cout << "build drink" << endl;
				fullness -= 0.6;
				energy -= 6;
				cout << "builder:  fullness -0.6 ; energy -6" << endl;
				drinking();
				createWax();
			}
			else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
				cout << "builder otdih" << endl;
				fullness -= 0.6;
				drink -= 0.2;
				cout << "builder:  fullness -0.6; drink -0.2" << endl;
				otdih();
				createWax();
			}
		};
};