#include <iostream>
#include <vector>

using namespace std;

class Area {
protected:
	Area* arr_hive = new Area[2];
	Area* arr_flowers = new Area[50];
public: 
	Area() {

	};
	~Area() {
		delete[] arr_hive;
		delete[] arr_flowers; 
	}
};


class Hive {
protected:
	int size;
	Hive* arr_hive = new Hive[size];
	double graz;
	double med;
	double nectar;
	double soty;
	double water;
	double vosk;

public:
	Hive() {
		vosk = 0;
		graz = 0;
		med = 0;
		water = 0;
		nectar = 0;
		soty = 0;
		cout << "const_hive" << endl;
	};
	~Hive() {
		cout << "destr_hive" << endl;
		delete[] arr_hive; 
	};
	
	void initial_condtion() {
		/*cout << "enter max size: " << endl;
		cin >> size; */
		cout << "Введите начальное количество меда" << endl;
		cin >> med;
		cout << "Введите начальное количество воды" << endl;
		cin >> water;
		cout << "Временно введите начальное количество нектара" << endl;
		cin >> nectar;
	};

	void foul() { //загрязняться
		graz += 1.5;
		cout << "graz=" << graz << endl;
	};

 	double editVosk(double toEdit) {
		return (vosk += toEdit);
	}
	double editGraz(double toEdit) {
		return (graz += toEdit);
	}
	double editSoty(double toEdit) {
		return(soty += toEdit);
	}
	double editNectar(double toEdit) {
		return (nectar += toEdit);
	}
	double editMed(double toEdit) {
		return (med += toEdit);
	}
	double editWater(double toEdit) {
		return (water += toEdit);
	}
	double getVosk() {
		return vosk;
	}
	double getNectar() {
		return nectar;
	}
	double getSoty() {
		return soty;
	}
	double getGraz() {
		return graz;
	}
	double getMed() {
		cout << "med:" << med << endl;
		return med;
	}
	double getWater() {
		return water;

	}
};


class Bees {

protected:
	int age;
	double wax;
	double sitost;
	int energy;
	double drink;
	Hive& obj_hive;
	vector<Bees> vec;
public:
	Bees(Hive& obj) : obj_hive(obj) {
		sitost = 25;
		energy = 110;
		drink = 25;
		wax = 0;
		cout << "const_bees" << endl;
	};

	~Bees() {
		cout << "destr_bees" << endl;
		//delete[] arr_bees;
	};
	vector<Bees>::iterator ITER;
	/*void editVector() {
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

	void createWax() {
		if (energy > 0 && sitost > 0 && drink > 0) {
			wax += 0.5;
			cout << "wax: " << wax << endl; 
		};
	};
	void otdih() {

		if (energy > 0 && energy < 110) {
			energy += 15;
			cout << "energy+15: " << energy << endl;
		}
		else  cout << "energy: " << energy << endl;
	};

	void drinking() {
		if (drink > 0 && drink <= 25 && obj_hive.getWater() > 0) {
			drink += 0.2;
			obj_hive.editWater(-0.2);
			cout << "drink +0.2 :" << drink << endl;
			cout << "water: " << obj_hive.getWater() << endl;
		}
		else cout << "drink:" << drink << endl;

	};

	virtual void eat_akt() = 0;
	virtual void die() = 0;
};


class Cleaner : public Bees {

public:
	Cleaner(Hive& obj) : Bees(obj) {};
	~Cleaner() {
		cout << "destr clean";
	};

	void test() {
		cout << obj_hive.getGraz() << endl;
	};
	void eat_akt() {
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
	void die() {
		this->~Cleaner();
		cout << "DIE CLEANER" << endl;
	};

	void cleaner_up() {

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

	void clean_wax() {

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
};

class Builder : public Bees {
public:
	Builder(Hive& obj) : Bees(obj) {};
	~Builder() {
		cout << "destr builder";
	};
	void eat_akt() {
		sitost += 0.6;
		cout << "sitosk +0.6" << endl;
		obj_hive.editMed(-0.6);
		cout << "med: " << obj_hive.getMed();
	};
	void die() {
		this->~Builder();
		cout << "DIE BUILDER" << endl;
	};
	void build() {
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
	void build_soty() {
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
					if (sitost > 0 && drink > 0 && energy > 0 &&  obj_hive.getVosk() > 0) {
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
	
};

class Queen : public Bees {
//protected:
	
public:
	Queen(Hive& obj) :Bees(obj) {};
	~Queen() {
		cout << "destr Queen";
	};
	void eat_akt() {
		sitost += 0.6;
		cout << "sitosk +0.6" << endl;
		obj_hive.editMed(-0.6);
		cout << "med: " << obj_hive.getMed();
	};
	void die() {
		this->~Queen();
		cout << "DIE Quuen" << endl;
	};
	void CreateBees() {
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
	void QueenLife() {
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
};



int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive;
	Cleaner obj_clean(obj_hive);
	Builder obj_build(obj_hive);
	Queen obj_queen(obj_hive);

	obj_hive.initial_condtion();
	
	for (int i = 0; i < 23; i++) {

		switch (i) {
		case 0:
			obj_hive.foul();
			obj_clean.test();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 1:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 2:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 3:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 4:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build_soty();
			break;
		case 5:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 6:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 7:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build_soty();
			break;
		case 8:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 9:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build_soty();
			break;
		case 10:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 11:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 12:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 13:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 14:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build_soty();
			break;
		case 15:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 16:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 17:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 18:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 19:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build_soty();
			break;
		case 20:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 21:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		case 22:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 23:
			obj_hive.foul();
			obj_clean.clean_wax();
			obj_build.build();
			break;
		};
	};
	system("pause");
	return 0;
};