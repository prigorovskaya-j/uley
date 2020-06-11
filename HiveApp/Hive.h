#pragma once

using namespace std;

class Hive
{
private:
	int size;
	Hive* arr_hive = new Hive[size];
	double mud;
	double honey;
	double nectar;
	double honeycombs;
	double water;
	double vosk;
    
public:
    Hive();
	~Hive();
    void foul();
    void initialCondtion();

	double editVosk(double toEdit);
	double editMud(double toEdit);
	double editHoneycombs(double toEdit);
	double editNectar(double toEdit);
	double editHoney(double toEdit);
	double editWater(double toEdit);

	double getVosk();
	double getNectar();
	double getHoneycombs();
	double getMud();
	double getHoney();
	double getWater();
};