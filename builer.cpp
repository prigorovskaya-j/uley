#include <iostream>

using namespace std;

//поле
class Area {
protected:
	//int hive[]; //улей
	int flovers[];
};


class Hive {
protected:
	//int bees[];
	double graz;
	double med;
	double nectar;
	double soty;
	double water;
public:
	Hive() {
		graz = 0;
		med = 0;
		water = 0;
		nectar = 0;
		soty = 0;
		cout << "const_hive" << endl;
	};
	~Hive() {
		cout << "destr_hive" << endl;
	};
	void initial_condtion() {
		cout << "������� ��������� ���������� ����" << endl;
		cin >> med;
		cout << "������� ��������� ���������� ����" << endl;
		cin >> water;
		cout << "�������� ������� ��������� ���������� �������" << endl;
		cin >> nectar;
	};

	void foul() { //������������
		graz += 1.5;
		cout << "graz=" << graz << endl;
	};

	/*	void build() {
			if(soty>1){
				cout<<"building hive"<<endl;
			}
		};*/
		/*	void divide() { //��������
				if(soty>1){
					cout<<"building hive"<<endl;
				}
			};
		*/
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
	double sitost;
	int energy;
	double drink;
	Hive& obj_hive;

public:


	Bees(Hive& obj) : obj_hive(obj) {
		sitost = 25;
		energy = 110;
		drink = 25;
		cout << "const_bees" << endl;
	};
	~Bees() {
		cout << "destr_bees" << endl;
	};

	void otdih() {

		if (energy > 0 && energy < 110) {
			energy += 15;
			cout << "energy+15: " << energy << endl;
		}
		else  cout << "energy: " << energy << endl;


	};

	virtual void eat_akt() = 0;

	void drinking() {
		if (drink > 0 && drink <= 25 && obj_hive.getWater() > 0) {
			drink += 0.2;
			obj_hive.editWater(-0.2);
			cout << "drink +0.2 :" << drink << endl;
			cout << "water: " << obj_hive.getWater() << endl;
		}
		else cout << "drink:" << drink << endl;

	};

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
						sitost -= 0.3;
						drink -= 0.2;
						energy -= 6;

						cout << "cleaner: graz -1; sitost -0.3; drink -0.2; energy -6" << endl;
						cout << "energy:" << energy << endl;
						cout << "drink:" << drink << endl;
						cout << "sitost" << sitost << endl;

					}
					else {
						cout << "graz =" << obj_hive.getGraz() << endl;
						cout << "energy=" << energy << endl;
						cout << "drink=" << drink << endl;
						cout << "sitost=" << sitost << endl;
					}
				};
				if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
					eat_akt();
					drink -= 0.2;
					energy -= 6;
					cout << "cleaner: drink -0.2; energy -6" << endl;
					cout << "energy:" << energy << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink < 25 && obj_hive.getWater()>0) {
					drinking();
					sitost -= 0.3;
					energy -= 6;
					cout << "cleaner: sitost -0.3; energy -6" << endl;
				}
				else if (energy < 110 && sitost>0 && drink > 0 && obj_hive.getMed() > 0 && obj_hive.getWater() > 0) {
					otdih();
					sitost -= 0.2;
					drink -= 0.2;
					cout << "cleaner: sitost -0.2; drink -0.2" << endl;
					cout << "sitost" << sitost << endl;
					cout << "drink:" << drink << endl;
				}
				else if (drink <= 0 || sitost <= 0 || energy <= 0) {
					die();
				}
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
						sitost -= 0.6;
						drink -= 0.2;
						energy -= 6;
						cout << "builder: " << endl; 
						cout << "nectar -1; med +0.7; sitost -0.6; drink -0.2; energy -6" << endl;
						cout << "energy:" << energy << endl;
						cout << "drink:" << drink << endl;
						cout << "sitost" << sitost << endl;

					}else {
						cout << "nectar =" << obj_hive.getNectar() << endl;
						cout << "med = " << obj_hive.getMed() << endl;
						cout << "energy=" << energy << endl;
						cout << "drink=" << drink << endl;
						cout << "sitost=" << sitost << endl;
					}
				};
				if (sitost > 0 && sitost < 25 && drink>0 && energy > 0 && obj_hive.getMed() > 0) {
					cout << "build eat" << endl;
					drink -= 0.2;
					energy -= 6;
					cout << "builder: drink -0.2; energy -6" << endl;
					eat_akt();
				}
				else if (sitost > 0 && drink > 0 && drink < 25 && energy>0 && obj_hive.getWater() > 0) {
					cout << "build drink" << endl;
					sitost -= 0.6;
					energy -= 6;
					cout << "builder:  sitost -0.6 ; energy -6" << endl;
					drinking();
				}
				else if (sitost > 0 && drink > 0 && energy > 0 && energy < 110) {
					cout << "builder otdih" << endl;
					sitost -= 0.6;
					drink -= 0.2;
					cout << "builder:  sitost -0.6; drink -0.2" << endl;
					otdih();
				}
				else if (drink <= 0 || sitost <= 0 || energy <= 0) {
					cout << "Builder die" << endl;
					die();
				};
			};

	};
	
};



int main() {
	setlocale(LC_ALL, "rus");
	Hive obj_hive;
	Cleaner obj_clean(obj_hive);
	Builder obj_build(obj_hive);

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
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 2:

			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 3:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 4:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 5:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 6:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 7:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 8:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 9:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
			break;
		case 10:
			obj_hive.foul();
			obj_clean.cleaner_up();
			obj_build.build();
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
}
