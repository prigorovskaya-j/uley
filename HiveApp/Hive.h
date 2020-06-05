#pragma once

using namespace std;

class Hive
{
private:
	int size;
	Hive* arr_hive = new Hive[size];
	double graz;
	double med;
	double nectar;
	double soty;
	double water;
	double vosk;
    
public:
    Hive();
	~Hive();
    void foul();
    void initial_condtion();
	double editVosk(double toEdit);
	double editGraz(double toEdit);
	double editSoty(double toEdit);
	double editNectar(double toEdit);
	double editMed(double toEdit);
	double editWater(double toEdit);
	double getVosk();
	double getNectar();
	double getSoty();
	double getGraz();
	double getMed();
	double getWater();
};