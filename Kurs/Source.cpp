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
	double dirt;
	double honey;
	double nectar;
	double honeycomb;
	double water;
	double beeswax;
	int size;

public:
	vector <Cleaner> arrayCleaner;
	vector <Builder> arrayBuilder;
	vector <Waterpot> arrayWaterpot;
	vector <Collector> arrayCollector;

	Hive(int size);
	~Hive() {
		cout << "destr_hive" << endl;
	};

	void initial_condtion() {
		cout << "¬ведите начальное количество меда" << endl;
		cin >> honey;
		cout << "¬ведите начальное количество воды" << endl;
		cin >> water;
		cout << "¬ременно введите начальное количество нектара" << endl;
		cin >> nectar;
	};

	void foul() {
		dirt += 1.5;
		cout << "dirt=" << dirt << endl;
	};

	double editBeeswax(double toEdit) {
		return (beeswax += toEdit);
	}
	double editDirt(double toEdit) {
		return (dirt += toEdit);
	}
	double editHoneycomb(double toEdit) {
		return(honeycomb += toEdit);
	}
	double editNectar(double toEdit) {
		return (nectar += toEdit);
	}
	double editHoney(double toEdit) {
		return (honey += toEdit);
	}
	double editWater(double toEdit) {
		return (water += toEdit);
	}
	double getBeeswax() {
		return beeswax;
	}
	double getNectar() {
		return nectar;
	}
	double getHoneycomb() {
		return honeycomb;
	}
	double getDirt() {
		return dirt;
	}
	double getHoney() {
		cout << "honey:" << honey << endl;
		return honey;
	}
	double getWater() {
		return water;
	}
};

class Bees {
protected:
	int age;
	double wax;
	double fullness;
	int energy;
	double drink;
	Hive& obj_hive;

public:
	Bees(Hive& obj) : obj_hive(obj) {
		fullness = 25;
		energy = 110;
		drink = 25;
		wax = 0;
		age = 0;
		cout << "const_bees" << endl;
	};

	~Bees() {
		cout << "destr_bees" << endl;
	};

	bool checkingDeath() {
		if (fullness <= 0 || drink <= 0 || energy <= 0) {
			return 0;
		}
		else { return 1; };
	};
	void createWax() {
		if (energy > 0 && fullness > 0 && drink > 0) {
			wax += 0.5;
			cout << "wax: " << wax << endl;
		};
	};
	void relax() {
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
	virtual void eatAktively() {};
};


class Cleaner : public Bees {
public:

	Cleaner(Hive& obj) : Bees(obj) {

	};

	~Cleaner() {
		cout << "destr clean";
	};

	void test() {
		cout << obj_hive.getDirt() << endl;
	};
	void eatAktively() {
		if (obj_hive.getHoney() > 0 && fullness > 0 && fullness <= 25) {
			obj_hive.editHoney(-0.3);	 
			fullness += 0.3;
			drink -= 0.2;
			cout << "cleaner: fullness +0.3= "<<fullness<<"; "<< "honey -0.3 = "<<obj_hive.getHoney()<<"; "<< "drink -0.2 = "<<drink << endl;
		}
		else cout << "Don't eat: fulness = " << fullness << ";" << "honey" << obj_hive.getHoney() << endl;

	};
	/*void die() override {
		this->~Cleaner();
		cout << "DIE CLEANER" << endl;
	};*/

	void cleanUp() {
			for (int i = 0; i < 60; i += 15) {
				cout << obj_hive.getDirt() << endl;
				if (obj_hive.getDirt() > 0) {
					obj_hive.editDirt(-1);
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;
					cout << "Cleaner clean: dirt -1 = " << obj_hive.getDirt()<< ";" << "fullness -0.3 = " << fullness << ";" << "drink -0.2 = " << drink << ";" << "energy -6 = " << energy << endl;
				}
				else cout << "Little dirt" << endl;
			};
			createWax();
	};
	
	void cleanWax() {
			cout << "Cleaner clean wax:" << endl;
			for (int i = 0; i < 60; i += 15) {
				if (wax > 0) {
					obj_hive.editBeeswax(0.5);
					wax -= 0.5;
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;
					cout << "Cleaner: beeswax +0.5 = " << obj_hive.getBeeswax() << "; " << "wax -0.5 = " << wax << "; " << "fullness -0.3 = " << fullness << "; " << "drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
					createWax();
				}
				else cout << "Little wax" << endl;
			};
	};
	void cleanerLife() {
		if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			eatAktively();
			drink -= 0.2;
			energy -= 6;
			cout << "Cleaner: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (drink > 0 && drink < 25 && obj_hive.getWater()>0 && energy > 0 && fullness > 0) {
			drinking();
			fullness -= 0.3;
			energy -= 6;
			cout << "Cleaner DRINK: fullness -0.3 = " << fullness << ";" << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (energy > 0 && energy < 110 && fullness>0 && drink > 0) {
			relax();
			fullness -= 0.2;
			drink -= 0.2;
			cout << "Cleaner RELAX: cleaner: fullness -0.2 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			createWax();
		}
	};
};

class Builder : public Bees {
public:
	Builder(Hive& obj) : Bees(obj) {

	};
	~Builder() {
		cout << "destr builder";
	};
	void eatAktively() {
		fullness += 0.6;
		obj_hive.editHoney(-0.6);
		cout << "Builder EAT: fulness +0.6 = "<<fullness<<"; " <<"honey: " << obj_hive.getHoney();
	};
	void builderLife() {
		if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			eatAktively();
			drink -= 0.2;
			energy -= 6;
			cout << "builder: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
			cout << "Builder DRINK: " << endl;
			drinking();
			fullness -= 0.6;
			energy -= 6;
			cout << "builder:  fullness -0.6 = " << fullness << "; " << " energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
			cout << "Builder RELAX: " << endl;
			relax();
			fullness -= 0.6;
			drink -= 0.2;
			cout << "builder: fullness -0.6 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			
			createWax();
		}
	};
	void build() {
		for (int i = 0; i < 60; i += 15) {
			if (obj_hive.getNectar() > 0) {
				cout << "Builder build honey: " << endl;
				obj_hive.editNectar(-1);	//Hive::dirt--;
				obj_hive.editHoney(0.7);
				fullness -= 0.6;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: " << endl;
				cout << "nectar -1 = " << obj_hive.getNectar() << "; " << "honey +0.7 = " << obj_hive.getHoney() << ";" << "fullness -0.6" << fullness << "; " << " drink -0.2 = " << drink << "; " << "energy -6 = " << energy << "." << endl;
			} else {
				cout << "little nectar =" << obj_hive.getNectar() << endl;
			};
		};
		createWax();
	};
	void buildHoneycomb() {
		for (int i = 0; i < 60; i += 15) {
			if (obj_hive.getBeeswax() > 0) {
				cout << "builder build honeycomb: " << endl;
				obj_hive.editBeeswax(-1);
				obj_hive.editHoneycomb(0.7);
				fullness -= 0.6;
				drink -= 0.2;
				energy -= 6;
				cout << "builder: beeswax -1 = "<<obj_hive.getBeeswax()<<";"<<"honeycomb +0.7 = "<< obj_hive.getHoneycomb()<<";"<<"fullness -0.6 = "<<fullness<<";" <<"drink -0.2 = "<<drink<<";"<<"energy -6 = " <<energy << endl;
				createWax();
			}
			else {
				createWax();
				cout << " little wax =" << obj_hive.getBeeswax() << endl;
			};
		};

	};
};

class Waterpot : public Bees {
public:
	Waterpot(Hive& obj) : Bees(obj) {

	};
	~Waterpot() {
		cout << "destr waterpot"<<endl;
	};
	void eatAktively() {
		fullness += 0.4;
		obj_hive.editHoney(-0.4);
		cout << "Waterpot EAT: sitosk +0.4 = " << fullness << "; " << "honey: " << obj_hive.getHoney() << endl;
	};
	
	void collectWater() {
		obj_hive.editWater(rand() % 2 + 1);
		cout << "Waterpot collect water: " << obj_hive.getWater()<<endl;
		fullness -= 0.4;
		energy -= 6;
		drink -= 0.2;
		cout << "Waterpot collect water:  fullness -0.4 = " << fullness << ";" << "drink -0.2 = " <<drink<< "; " << "energy -6 = " << energy << endl;
		createWax();
	};
	void waterpotLife() {
		if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			drink -= 0.2;
			energy -= 6;
			eatAktively();
			cout << "waterpot: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
			cout << "Waterpot DRINK: " << endl;
			drinking();
			fullness -= 0.4;
			energy -= 6;
			cout << "waterpot:  fullness -0.4 "<< fullness<< "; "<< "energy -6 = "<< energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
			cout << "Waterpot RELAX: " << endl;
			relax();
			fullness -= 0.6;
			drink -= 0.2;
			cout << "Waterpot:  fullness -0.6 = "<<fullness<<"; "<< "drink -0.2 = "<< drink << endl;
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
	void eatAktively() {
		fullness += 0.4;
		obj_hive.editHoney(-0.4);
		cout << "Collector EAT: sitosk +0.4 = " << fullness << "; " << "honey: " << obj_hive.getHoney() << endl;;
	};
	
	void collectorLife() {
		if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			drink -= 0.2;
			energy -= 6;
			eatAktively();
			cout << "collector: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
			cout << "Collector DRINK :" << endl;
			fullness -= 0.4;
			energy -= 6;
			cout << "collector:  fullness -0.4 = " << fullness << "; " << " energy -6 = " << energy << endl;
			drinking();
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 110) {
			cout << "Collector RELAX:" << endl;
			relax();
			fullness -= 0.4;
			drink -= 0.2;
			cout << "collector: fullness -0.4 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			createWax();
		}
	};
	void collectNectar(Flowers obj_flow) {
		cout << "Collector collect nectar: " << endl;
		if (obj_flow.getNectarFlower() > 0) {
			double ran;
			ran = rand() % 2 - 1;
			obj_hive.editNectar(ran);
			obj_flow.editNectarFlower(-ran);
			cout << "Nectar " << ran << "= " << obj_hive.getNectar() << endl;
			cout << "Nectar in flowers " << ran << " = " << obj_flow.getNectarFlower() << endl;
		}
		else cout << "Little nectar in flowers" <<obj_flow.getNectarFlower()<< endl;

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

	beeswax = 0;
	this->size = size;
	dirt = 0;
	honey = 0;
	water = 0;
	nectar = 0;
	honeycomb = 0;
	cout << "const_hive" << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive(1);
	Flowers obj_flow;

	obj_hive.initial_condtion();

for (int i = 0; i < 23; i++) {
		switch (i) {
		case 0:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanUp(); 
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; } 
				else obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 1:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 2:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 3:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectorLife();
			};
			break;
		case 4:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << "Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 5:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 6:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if(obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if(obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << "Collector is death" << endl; }
				else obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 7:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if(obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if(obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectorLife();
			};
		case 8:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "  Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 9:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "  Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 10:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 11:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "  Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectorLife();
			};
			break;
		case 12:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 13:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 14:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 15:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << "Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectorLife();
			};
			break;
		case 16:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 17:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << "Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 18:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 19:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectorLife();
			};
			break;
		case 20:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << "Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 21:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << "  Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanUp();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].build();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 22:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanWax();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].buildHoneycomb();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].collectWater();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectNectar(obj_flow);
			};
			break;
		case 23:
			obj_hive.foul();
			for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
				if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { cout << " Cleaner is death" << endl; }
				else
				obj_hive.arrayCleaner[i].cleanerLife();
			};
			for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
				if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { cout << " Builder is death" << endl; }
				else
				obj_hive.arrayBuilder[i].builderLife();
			};
			for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
				if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { cout << " Waterpot is death" << endl; }
				else
				obj_hive.arrayWaterpot[i].waterpotLife();
			};
			for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
				if (obj_hive.arrayCollector[i].checkingDeath() == 0) { cout << " Collector is death" << endl; }
				else
				obj_hive.arrayCollector[i].collectorLife();
			};
			break;
		};
	};
	system("pause");
	return 0;
};