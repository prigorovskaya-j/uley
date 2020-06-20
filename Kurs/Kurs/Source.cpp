#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

using namespace std;
fstream out;

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
		nectarFlower = 100;
	};
	~Flowers() {
	
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
	};

	void initial_condtion() {
		cout << "Введите начальное количество меда" << endl;
		cin >> honey;
		cout << "Введите начальное количество воды" << endl;
		cin >> water;
		cout << "Временно введите начальное количество нектара" << endl;
		cin >> nectar;
	};

	void foul() {
		dirt += 1.5;
		out << "dirt=" << dirt << endl;
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
		out << "honey:" << honey << endl;
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
		fullness = 100;
		energy = 1000;
		drink = 100;
		wax = 0;
		age = 0;
		out << "const_bees" << endl;
	};

	~Bees() {
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
			out << "wax: " << wax << endl;
		};
	};
	void relax() {
		if (energy > 0 && energy < 1000) {
			energy += 15;
			out << "energy+15: " << energy << endl;
		}
		else  out << "energy: " << energy << endl;
	};
	void drinking() {
		if (drink > 0 && drink <= 100 && obj_hive.getWater() > 0) {
			drink += 0.2;
			obj_hive.editWater(-0.2);
			out << "drink +0.2 :" << drink << endl;
			out << "water: " << obj_hive.getWater() << endl;
		}
		else out << "drink:" << drink << endl;

	};
	virtual void eatAktively() {};
};


class Cleaner : public Bees {
public:

	Cleaner(Hive& obj) : Bees(obj) {

	};

	~Cleaner() {
	};

	void test() {
		out << obj_hive.getDirt() << endl;
	};
	void eatAktively() {
		if (obj_hive.getHoney() > 0 && fullness > 0 && fullness <= 25) {
			obj_hive.editHoney(-0.3);	 
			fullness += 0.3;
			drink -= 0.2;
			out << "cleaner: fullness +0.3= "<<fullness<<"; "<< "honey -0.3 = "<<obj_hive.getHoney()<<"; "<< "drink -0.2 = "<<drink << endl;
		}
		else out << "Don't eat: fulness = " << fullness << ";" << "honey" << obj_hive.getHoney() << endl;

	};

	void cleanUp() {
			for (int i = 0; i < 60; i += 15) {
				out << obj_hive.getDirt() << endl;
				if (obj_hive.getDirt() > 0) {
					obj_hive.editDirt(-1);
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;
					out << "Cleaner clean: dirt -1 = " << obj_hive.getDirt()<< ";" << "fullness -0.3 = " << fullness << ";" << "drink -0.2 = " << drink << ";" << "energy -6 = " << energy << endl;
				}
				else out << "Little dirt" << endl;
			};
			createWax();
	};
	
	void cleanWax() {
			out << "Cleaner clean wax:" << endl;
			for (int i = 0; i < 60; i += 15) {
				if (wax > 0) {
					obj_hive.editBeeswax(0.5);
					wax -= 0.5;
					fullness -= 0.3;
					drink -= 0.2;
					energy -= 6;
					out << "Cleaner: beeswax +0.5 = " << obj_hive.getBeeswax() << "; " << "wax -0.5 = " << wax << "; " << "fullness -0.3 = " << fullness << "; " << "drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
					createWax();
				}
				else out << "Little wax" << endl;
			};
	};
	void cleanerLife() {
		if (fullness > 0 && fullness < 25 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			eatAktively();
			drink -= 0.2;
			energy -= 6;
			out << "Cleaner: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (drink > 0 && drink < 25 && obj_hive.getWater()>0 && energy > 0 && fullness > 0) {
			drinking();
			fullness -= 0.3;
			energy -= 6;
			out << "Cleaner DRINK: fullness -0.3 = " << fullness << ";" << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (energy > 0 && energy < 110 && fullness>0 && drink > 0) {
			relax();
			fullness -= 0.2;
			drink -= 0.2;
			out << "Cleaner RELAX: cleaner: fullness -0.2 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			createWax();
		}
	};
};

class Builder : public Bees {
public:
	Builder(Hive& obj) : Bees(obj) {

	};
	~Builder() {
	};
	void eatAktively() {
		fullness += 0.6;
		obj_hive.editHoney(-0.6);
		out << "Builder EAT: fulness +0.6 = "<<fullness<<"; " <<"honey: " << obj_hive.getHoney();
	};
	void builderLife() {
		if (fullness > 0 && fullness < 100 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			eatAktively();
			drink -= 0.2;
			energy -= 6;
			out << "builder: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 100 && energy>0 && obj_hive.getWater() > 0) {
			out << "Builder DRINK: " << endl;
			drinking();
			fullness -= 0.6;
			energy -= 6;
			out << "builder:  fullness -0.6 = " << fullness << "; " << " energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 1000) {
			out << "Builder RELAX: " << endl;
			relax();
			fullness -= 0.6;
			drink -= 0.2;
			out << "builder: fullness -0.6 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			
			createWax();
		}
	};
	void build() {
		for (int i = 0; i < 60; i += 15) {
			if (obj_hive.getNectar() > 0) {
				out << "Builder build honey: " << endl;
				obj_hive.editNectar(-1);	//Hive::dirt--;
				obj_hive.editHoney(0.7);
				fullness -= 0.6;
				drink -= 0.2;
				energy -= 6;
				out << "builder: " << endl;
				out << "nectar -1 = " << obj_hive.getNectar() << "; " << "honey +0.7 = " << obj_hive.getHoney() << ";" << "fullness -0.6" << fullness << "; " << " drink -0.2 = " << drink << "; " << "energy -6 = " << energy << "." << endl;
			} else {
				out << "little nectar =" << obj_hive.getNectar() << endl;
			};
		};
		createWax();
	};
	void buildHoneycomb() {
		for (int i = 0; i < 60; i += 15) {
			if (obj_hive.getBeeswax() > 0) {
				out << "builder build honeycomb: " << endl;
				obj_hive.editBeeswax(-1);
				obj_hive.editHoneycomb(0.7);
				fullness -= 0.6;
				drink -= 0.2;
				energy -= 6;
				out << "builder: beeswax -1 = "<<obj_hive.getBeeswax()<<";"<<"honeycomb +0.7 = "<< obj_hive.getHoneycomb()<<";"<<"fullness -0.6 = "<<fullness<<";" <<"drink -0.2 = "<<drink<<";"<<"energy -6 = " <<energy << endl;
				createWax();
			}
			else {
				createWax();
				out << " little wax =" << obj_hive.getBeeswax() << endl;
			};
		};

	};
};

class Waterpot : public Bees {
public:
	Waterpot(Hive& obj) : Bees(obj) {

	};
	~Waterpot() {
	};
	void eatAktively() {
		fullness += 0.4;
		obj_hive.editHoney(-0.4);
		out << "Waterpot EAT: sitosk +0.4 = " << fullness << "; " << "honey: " << obj_hive.getHoney() << endl;
	};
	
	void collectWater() {
		obj_hive.editWater(rand() % 2 + 1);
		out << "Waterpot collect water: " << obj_hive.getWater()<<endl;
		fullness -= 0.4;
		energy -= 6;
		drink -= 0.2;
		out << "Waterpot collect water:  fullness -0.4 = " << fullness << ";" << "drink -0.2 = " <<drink<< "; " << "energy -6 = " << energy << endl;
		createWax();
	};
	void waterpotLife() {
		if (fullness > 0 && fullness < 100 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			drink -= 0.2;
			energy -= 6;
			eatAktively();
			out << "waterpot: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 100 && energy>0 && obj_hive.getWater() > 0) {
			out << "Waterpot DRINK: " << endl;
			drinking();
			fullness -= 0.4;
			energy -= 6;
			out << "waterpot:  fullness -0.4 "<< fullness<< "; "<< "energy -6 = "<< energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 1000) {
			out << "Waterpot RELAX: " << endl;
			relax();
			fullness -= 0.6;
			drink -= 0.2;
			out << "Waterpot:  fullness -0.6 = "<<fullness<<"; "<< "drink -0.2 = "<< drink << endl;
			createWax();
		}
	};
};

class Collector : public Bees{
public:
	Collector(Hive& obj) : Bees(obj) {

	};
	~Collector() {

	};
	void eatAktively() {
		fullness += 0.4;
		obj_hive.editHoney(-0.4);
		out << "Collector EAT: sitosk +0.4 = " << fullness << "; " << "honey: " << obj_hive.getHoney() << endl;;
	};
	
	void collectorLife() {
		if (fullness > 0 && fullness < 100 && drink>0 && energy > 0 && obj_hive.getHoney() > 0) {
			drink -= 0.2;
			energy -= 6;
			eatAktively();
			out << "collector: drink -0.2 = " << drink << "; " << "energy -6 = " << energy << endl;
			createWax();
		}
		else if (fullness > 0 && drink > 0 && drink < 100 && energy>0 && obj_hive.getWater() > 0) {
			out << "Collector DRINK :" << endl;
			fullness -= 0.4;
			energy -= 6;
			out << "collector:  fullness -0.4 = " << fullness << "; " << " energy -6 = " << energy << endl;
			drinking();
			createWax();
		}
		else if (fullness > 0 && drink > 0 && energy > 0 && energy < 1000) {
			out << "Collector RELAX:" << endl;
			relax();
			fullness -= 0.4;
			drink -= 0.2;
			out << "collector: fullness -0.4 = " << fullness << "; " << "drink -0.2 = " << drink << endl;
			createWax();
		}
	};
	void collectNectar(Flowers obj_flow) {
		out << "Collector collect nectar: " << endl;
		if (obj_flow.getNectarFlower() > 0) {
			double ran;
			ran = rand() % 2 - 1;
			obj_hive.editNectar(ran);
			obj_flow.editNectarFlower(-ran);
			out << "Nectar " << ran << "= " << obj_hive.getNectar() << endl;
			out << "Nectar in flowers " << ran << " = " << obj_flow.getNectarFlower() << endl;
		}
		else out << "Little nectar in flowers" <<obj_flow.getNectarFlower()<< endl;

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
	out << "const_hive" << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive(10);
	Flowers obj_flow;
	int n;
	cout << "Добро пожаловать в улей!" << endl;
	cout << "Если вы хотите начать, то нажмите 1, если хотите выйти, то нажмите 0" << endl;
	cin >> n;
	switch (n) {
	case 1:{
		cout << "Вы выбрали начать работу! Добро пожаловать в мир пчелок :)" << endl;
		cout << "К сожалению, матки в этом улье нет, так что новых пчел в ульей не появляется" << endl;
		
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0ccxd; l0XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0 : lOk:cOXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk, : dkXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXldNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNocKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0, oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMx.dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMN00NWWMMMMMMMMMMMMMMMNKk, ':ccclodkKNMMMMMMMMMMMMMMMWXK0OO0XWMMMMMMMMMMMM" << endl;
			cout << "MMMMMMWkcloldKXXXXXNWMMMMWKxc, ''; :clllc;; , ..'cxXMMMMMMMMN0xc;''', , ''; dKWMM" << endl;
			cout << "MMMMMMWc; XMx'cxdddddollxxc..:d0XWMMMMMMMMWKOo;.'lKWMMW0o, .':ok0KXXKk:.'OWMMMMMM" << endl;
			cout << "MMMMMMM0ololdNMMMMMWXO : 'dKWMWMMMMMMMMMMMMMMW0c..dKk:..ckXWMMMMMMMMNl ;XMMMMMMMM" << endl;
			cout << "MMMMMMMMMNKNMMMMMMMMWO'.cKMMMMWMMMMMMM0lco0WMMWWO,...'dXWMMMMMMMMMMMMx.'MMMMMMMMM" << endl;
			cout << "MMMMMMMMWWMMMMMMMMMM0'.oNMMMMMMMMMMMMWo    .lXWMMMK; ,0WWMMMMMMMMMMMMWo ;XMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMN : cNMMMMMMMMMMMMMM0'    lNMMMMk..OMMMMMMMMMMMMMMO..xWMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMO..kMWMWkco0WMMMMMMW0d;, KMMMMK, dMMMMMMMMMMMMMK; lNMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMk..OMWMN:.dNMMMMMMMMNOdOWMMMM0, dMMMMMMMMMMMWO, .cXMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMM0'.xWMMWk.  .dWMMMMMMMWNWWMMMMWx..OMMMMMMMMMMXo..dNMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMNo; KMWWWO;  :NMMMWKxo:lNMWMMM0, , OWMMMMMMMXd'.:0WMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMM0, ; KMMMMNOxKWMW0c.    oNMMMWO, ., lONWN0l' .cOXNWMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMWMMMMNKkdc; , .  'xNMMMMMMMMMN0xdxONMMWKo.  ,dko,.', , ....., , ''; cd0N" << endl;
			cout << "MMMMMMMMMWWXxc, .';coxkkd;.,oONWMMMMMMMMMMMWXkl. .:kNMMMNx'.o0KXXKK0xo:.., xXMMMM" << endl;
			cout << "MMMMMMMMW0c..; dOXWMMMMMMNOc'.':ldxkOOkxdol; . ., o0WMMMMMWk..kWMMMMMMMWXx, .:KMM" << endl;
			cout << "MMMMMMMXo..l0WMMMMMMMMMMMMWXOdl : .         .; oONMMMMWMNO:., 0MMMMMMMMMM0'.dMMMM" << endl;
			cout << "MMMMMMXc.; 0WMMMMMMMMMMMMMMMMMMMWo ., :coxk0XWMMMMMMWXx; .oWMMMMMMMMNd..OMMMMMMMM" << endl;
			cout << "MMMMMMk..OMMMMMMMMMMMMMMMMMMMMMNc cNMMMMMMMMMMMWKx : .       ..: NMMMWNKkl,.;OWMM" << endl;
			cout << "MMMMMMO..xWWMMMMMMMMMMMMMMMMMMWK, :NMMMMMMWNKkl; ..ck;.ccc:; , '';lONMMMMMMMMMMMM" << endl;
			cout << "MMMMMMNx..l0NMMMMMMMMMMMMMMMNkc...xKOkxoo:'.          .c0Nx..;cclodxOXWMMMMMMMMMM" << endl;
			cout << "MMMMMMMW0l'.,cdxO0KKKK00kxdc'.'dOc ..               .;dKWMK, lNMMMMMMMMMMMMMMMMMM" << endl;
			cout << "; , '''''''', ..oXWMK:              . : d0WMMMX :.cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMWNXK0000KK0 : ; 0WMMMMNx'      ..;cdOXWMMMWNk, ;XMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMNl.; KMMMMMMMMXx'    'lk0XWMMMWKd; ..xMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMx.'OMMMMMMMMMMK;  ,lc,''', :ll; ..OMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMN : cWMMMMMMMMWk'.cOXMWWX0kdoc,.     .kMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMK, oMMMMMMMW0c.'xNMMMMMMMMMMMWXOd:.  dWMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMNc; KWMMNKx:..oKWMMMMMMMMMMMMMMMMMXko0WMMMMMMMMMMMMMMMMMMMM" << endl;
			cout << "MMMMMMMMMMMMMMMMMMMMMMMXo.. : c : , .':xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
			
			
	out.open("result.txt", ios::app);
	obj_hive.initial_condtion();
	if (out.is_open())
	{
	for (int i = 1; i <= 30; i++) {
		out << "                                       DAY " << i << endl;
		out << "==================================================================================================" << endl;
		for (int i = 0; i < 23; i++) {

			switch (i) {
			case 0:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 1:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 2:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 3:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectorLife();
				};
				break;
			case 4:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << "Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 5:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 6:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << "Collector is death" << endl; }
					else obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 7:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectorLife();
				};
			case 8:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "  Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 9:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "  Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 10:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 11:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "  Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectorLife();
				};
				break;
			case 12:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 13:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 14:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 15:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << "Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectorLife();
				};
				break;
			case 16:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 17:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << "Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 18:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 19:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectorLife();
				};
				break;
			case 20:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << "Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 21:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << "  Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanUp();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].build();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 22:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanWax();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].buildHoneycomb();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].collectWater();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectNectar(obj_flow);
				};
				break;
			case 23:
				obj_hive.foul();
				for (vector<Cleaner>::size_type i = 0; i != obj_hive.arrayCleaner.size(); i++) {
					if (obj_hive.arrayCleaner[i].checkingDeath() == 0) { out << " Cleaner is death" << endl; }
					else
						obj_hive.arrayCleaner[i].cleanerLife();
				};
				for (vector<Builder>::size_type i = 0; i != obj_hive.arrayBuilder.size(); i++) {
					if (obj_hive.arrayBuilder[i].checkingDeath() == 0) { out << " Builder is death" << endl; }
					else
						obj_hive.arrayBuilder[i].builderLife();
				};
				for (vector<Waterpot>::size_type i = 0; i != obj_hive.arrayWaterpot.size(); i++) {
					if (obj_hive.arrayWaterpot[i].checkingDeath() == 0) { out << " Waterpot is death" << endl; }
					else
						obj_hive.arrayWaterpot[i].waterpotLife();
				};
				for (vector<Collector>::size_type i = 0; i != obj_hive.arrayCollector.size(); i++) {
					if (obj_hive.arrayCollector[i].checkingDeath() == 0) { out << " Collector is death" << endl; }
					else
						obj_hive.arrayCollector[i].collectorLife();
				};
				break;
			};

		};
		out << "==================================================================================================" << endl;

		cout << "Подождите, файл еще записывается!" << endl;
	};
	
	}
	else { cout << "Error open file" << endl; }
	cout << "Файл записался, вы можете найти данные в папке проекта в файле result.txt" << endl;
	cout << "К сожалению, пчелки умерли, но когда-нибудь улей будет процветать!" << endl;
	system("pause");
	break;
	}
	case 0:
		return 0;
		break;
	}
	system("pause");
	return 0;
};
