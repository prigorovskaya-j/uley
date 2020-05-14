#include <iostream>

using namespace std;

//РїРѕР»Рµ
class Area {
protected:
	//int hive[]; //СѓР»РµР№
	int flovers[];
};


class Hive {
protected:
	//int bees[];
	double graz;
	double med;
	int water;
public:
	Hive() {
		graz = 0;
		med = 0;
		water = 0;
		cout << "const_hive" << endl;
	};
	~Hive() {
		cout << "destr_hive" << endl;
	};
	void initial_condtion() {
		cout << "Введите начальное количество меда" << endl;
		cin >> med;
		cout << "Введите начальное количество воды" << endl;
		cin >> water;
	};
	void foul() { //загрязняться
		graz += 1.5;
		cout<<"graz="<<graz<<endl;
	};

	void build() {
	};
	void divide() { //делиться
	};
	double editGraz(double toEdit) { 
		return (graz += toEdit);
	}
	double editMed(double toEdit) { 
		return (med += toEdit);
	}
	int editWater(int toEdit) { 
		return (water += toEdit);
	}
	double getGraz() {
		return graz;
	}
	double getMed() {
		return med;
	}
	int getWater() {
		return water;
	}
};


class Bees {

protected:
	int age;
	double sitost;
	int energy;
	double drink;
	Hive& obj_hive;

public:


	Bees(Hive &obj) : obj_hive (obj) {
		sitost = 25;
		energy = 110;
		drink = 25;
		cout << "const_bees" << endl;
	};
	~Bees() {
		cout << "destr_bees" << endl;
	};

	void otdih() {
		//for(int i=0;i<7; i++){
		energy += 15;
		cout << "energy+15: " <<energy<< endl;
		//}
	};

	//		virtual void eat_pok()=0;

	virtual void eat_akt() = 0;

	void drinking() {
		drink += 0.2;
		cout << "drink +0.2" << endl;
		cout<<"drink:"<<drink<<endl;
	};
	void die() {
	};
};


class Cleaner : public Bees {

public:
	Cleaner(Hive& obj) : Bees(obj) {}
	void test() {
		cout << obj_hive.getGraz() << endl;
	}
	void eat_akt() {
		obj_hive.editMed(-0.3);		//Hive::med-=0.3;
		sitost += 0.3;
		cout << "sitost +0.3; med -0.3" << endl;
		cout<<"sitost"<<sitost<<endl;
	};
	void cleaner_up() {
		for (int i = 0; i < 60; i += 15) {
			cout << obj_hive.getGraz();
			if (obj_hive.getGraz() != 0) { //Hive::graz!=0
				obj_hive.editGraz(-1);	//Hive::graz--;
				sitost -= 0.3;
				drink -= 0.2;
				energy -= 6;
				cout << "graz -1; sitost -0.3; drink -0.2; energy -6" << endl;
				cout<<"energy:"<<energy<<endl;
				cout<<"drink:"<<drink<<endl;
				cout<<"sitost"<<sitost<<endl;

			}
			else if (sitost < 25) {
				eat_akt();
				drink -= 0.2;
				energy -= 6;
				cout << "drink -0.2; energy -6" << endl;
				cout<<"energy:"<<energy<<endl;
				cout<<"drink:"<<drink<<endl;
			}
			else if (drink < 25) {
				drinking();
			}
			else if (energy < 110) {
				otdih();
				sitost -= 0.2;
				drink -= 0.2;
				cout << "sitost -0.2; drink -0.2" << endl;
				cout<<"sitost"<<sitost<<endl;
				cout<<"drink:"<<drink<<endl;
			}
		}

	};
};



int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive;
	Cleaner obj_clean(obj_hive);
	obj_hive.initial_condtion();
	
	for (int i = 0; i < 23; i++) {

		switch (i) {
		case 0:
			obj_hive.foul();
			obj_clean.test();
			obj_clean.cleaner_up();
			break;
		case 1:

			obj_hive.foul();
			obj_clean.cleaner_up();
			break;
		case 2:

			obj_hive.foul();
			obj_clean.cleaner_up();
			break;
		case 3:
			obj_hive.foul();
			obj_clean.cleaner_up();

			break;
		case 4:
			obj_hive.foul();
			obj_clean.cleaner_up();
			break;
		case 5:
			obj_hive.foul();
			obj_clean.cleaner_up();
			break;
		case 6:
			obj_hive.foul();
			obj_clean.cleaner_up();
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

		}


	}
	system("pause");
	return 0;
}
