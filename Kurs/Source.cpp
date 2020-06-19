#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class Area;
class Hive;
class Bees;
class Cleaner;
class Builder;
class Collector;
class Waterpot;

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

class Flowers {
protected: 
	double nectarFlower;
public: 
	Flowers() {
		nectarFlower = 10;
	};
	~Flowers() {
		cout << "destr_flo" << endl;
	};
	double editNectarFlower(double toEdit) {
		return (nectarFlower += toEdit);
	}
	double getNectarFlower() { return nectarFlower; };
	void createNectar() {
		double ran;
		ran = rand() % 2 - 1;
		nectarFlower += ran;
	};

};

class Hive {
protected:
	

	//Hive* arr_hive = new Hive[size];
	double graz;
	double med;
	double nectar;
	double soty;
	double water;
	double vosk;
	int size;

public:

	vector <Cleaner> arrayCleaner;
	vector <Builder> arrayBuilder;
	vector <Waterpot> arrayWaterpot;
	vector <Collector> arrayCollector;

	Hive(int size);
	~Hive() {
		cout << "destr_hive" << endl;
		//delete[] arr_hive;
	};

	void initial_condtion() {
		cout << "¬ведите начальное количество меда" << endl;
		cin >> med;
		cout << "¬ведите начальное количество воды" << endl;
		cin >> water;
		cout << "¬ременно введите начальное количество нектара" << endl;
		cin >> nectar;
	};

	void foul() { //загр€зн€тьс€
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
public:

	Bees(Hive& obj) : obj_hive(obj) {
		sitost = 25;
		energy = 110;
		drink = 25;
		wax = 0;
		age = 0;
		cout << "const_bees" << endl;
	};

	~Bees() {
		cout << "destr_bees" << endl;
		//delete[] arr_bees;
	};

	void checkingDeath() {
		if (sitost <= 0 || drink <= 0 || energy <= 0) {
			die();
		}
		else { cout << "bees life" << endl; };
	};

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

	virtual void eat_akt() {};
	virtual void die() {};
};


class Cleaner : public Bees {
public:

	Cleaner(Hive& obj) : Bees(obj) {

	};

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
				};
			};
	};

	void clean_wax() {
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
				};
			};
	};
};

class Builder : public Bees {
public:
	Builder(Hive& obj) : Bees(obj) {

	};
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
			};

	};
	void build_soty() {
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
			};
	};

};

class Waterpot : public Bees {
public:
	Waterpot(Hive& obj) : Bees(obj) {

	};
	~Waterpot() {
		cout << "destr builder";
	};
	void eat_akt() {
		sitost += 0.4;
		cout << "sitosk +0.6" << endl;
		obj_hive.editMed(-0.6);
		cout << "med: " << obj_hive.getMed();
	};
	void die() {
		this->~Waterpot();
		cout << "DIE Waterpot" << endl;
	};
	void collectWater() {
		obj_hive.editWater(rand() % 2 + 1);
		cout << "water ++:" << obj_hive.getWater();
		sitost -= 0.4;
		energy -= 6;
		drink -= 0.2;
		cout << "Waterpot:  sitost -0.6; drink -0.2; energy -6" << endl;
		createWax();
	};
	void waterpotLife() {
		if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
			cout << "waterpot eat" << endl;
			drink -= 0.2;
			energy -= 6;
			cout << "waterpot: drink -0.2; energy -6" << endl;
			eat_akt();
			createWax();
		}
		else if (sitost > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
			cout << "waterpot drink" << endl;
			sitost -= 0.6;
			energy -= 6;
			cout << "waterpot:  sitost -0.6 ; energy -6" << endl;
			drinking();
			createWax();
		}
		else if (sitost > 0 && drink > 0 && energy > 0 && energy < 110) {
			cout << "waterpot otdih" << endl;
			sitost -= 0.6;
			drink -= 0.2;
			cout << "waterpot:  sitost -0.6; drink -0.2" << endl;
			otdih();
			createWax();
		}
	};
};

class Collector : public Bees{
public:
	Collector(Hive& obj) : Bees(obj) {

	};
	~Collector() {
		cout << "destr Collector";
	};
	void eat_akt() {
		sitost += 0.4;
		cout << "sitosk +0.6" << endl;
		obj_hive.editMed(-0.6);
		cout << "med: " << obj_hive.getMed();
	};
	void die() {
		this->~Collector();
		cout << "DIE Collector" << endl;
	};
	void collectNectar(Flowers obj_flow) {
		double ran;
		ran = rand() % 2 - 1;
		obj_hive.editNectar(ran);
		obj_flow.editNectarFlower(-ran);
		cout<<"Nectar in flowers:"<<obj_flow.getNectarFlower()<<endl;
	};
};
Hive::Hive(int size) {
	for (int i = 0; i < size; i++)
	{
		Cleaner* cleaner = new Cleaner(*this);
		arrayCleaner.push_back(*cleaner);
	}

	for (int i = 0; i < size; i++)
	{
		Builder* builder = new Builder(*this);
		arrayBuilder.push_back(*builder);
	}

	for (int i = 0; i < size; i++)
	{
		Waterpot* waterpot = new Waterpot(*this);
		arrayWaterpot.push_back(*waterpot);
	}
	for (int i = 0; i < size; i++)
	{
		Collector* collector = new Collector(*this);
		arrayCollector.push_back(*collector);
	}

	vosk = 0;
	this->size = size;
	graz = 0;
	med = 0;
	water = 0;
	nectar = 0;
	soty = 0;
	cout << "const_hive" << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive(10);
	Flowers obj_flow;

	obj_hive.initial_condtion();

for (int i = 0; i < 23; i++) {
		switch (i) {
		case 0:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				obj_hive.arrayCleaner[i].checkingDeath();
				obj_hive.arrayCleaner[i].cleaner_up();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				obj_hive.arrayBuilder[i].checkingDeath();
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				obj_hive.arrayWaterpot[i].checkingDeath();
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				obj_hive.arrayCollector[i].checkingDeath();
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 1:
			obj_hive.foul();
		
			break;
		case 2:
			obj_hive.foul();
			
			break;
		case 3:
			obj_hive.foul();
			
			break;
		case 4:
			obj_hive.foul();
			
			break;
		case 5:
			obj_hive.foul();
		
			break;
		case 6:
			obj_hive.foul();
			
			break;
		case 7:
			obj_hive.foul();
	
			break;
		case 8:
			obj_hive.foul();
		
			break;
		case 9:
			obj_hive.foul();
		
			break;
		case 10:
			obj_hive.foul();
		
			break;
		case 11:
			obj_hive.foul();
		
			break;
		case 12:
			obj_hive.foul();
		
			break;
		case 13:
			obj_hive.foul();
		
			break;
		case 14:
			obj_hive.foul();
			
			break;
		case 15:
			obj_hive.foul();
			
			break;
		case 16:
			obj_hive.foul();
			
			break;
		case 17:
			obj_hive.foul();
		
			break;
		case 18:
			obj_hive.foul();
			
			break;
		case 19:
			obj_hive.foul();
		
			break;
		case 20:
			obj_hive.foul();
		
			break;
		case 21:
			obj_hive.foul();
		
			break;
		case 22:
			obj_hive.foul();
			
			break;
		case 23:
			obj_hive.foul();
		
			break;
		};
	};
	
	system("pause");
	return 0;
};