#include <iostream>

using namespace std; 

//поле
class Area{
	int hive[]; //улей
	int flovers[];
};

class Hive{
	int bees[];
	int graz=0;
	int med;
	int water;
	
	public:
	void foul(){ //загр€зн€тьс€
		//for (int i=0; i<24; i=i+2){
			graz=graz+1.5;
		//}	
	};
	void build(){ 
	};
	void divide(){ //делитьс€
	};
};

class Bees:public Hive{
	int age;
	int sitost=25;
	int energy=110;
	int drink=25;
	
	public:
		void otdih(){
			//for(int i=0;i<7; i++){
				energy+=15;
			//}
		};
		
		virtual void eat_pok()=0;
		
		virtual void eat_akt()=0;
		
		void drinking(){
		
			drink+=0.2;
		};
		die(){
		};
};

class Working:public Bees{
	void virtual func()=0;
};

class  Cleaner: public Working, public Hive{
	public:
	void cleaner_up(){
			for (int i=0; i<60; i+=15){
			if(graz!=0){
					graz--;
					sitost-=0.3;
					drink-=0.2;
					energy-=6;
				
			} else if (sitost<25){
							eat_akt();
							drink-=0.2;
							energy-=6;
					} else if(drink<25){
								drinking();
							} else if(energy<110){
								otdih();
								sitost-=0.2;
								drink-=0.2;
							}
			}
									
		};
};

void initial_condtion(){
	cout<<"¬ведите начальное количество меда";
	cin>>med;
	cout<<"¬ведите начальное количество воды";
	cin>>water;
};

int main(){
	setlocale(LC_ALL, "rus");
	Cleaner obj_clean;
	Hive obj_hive;
	initial_condtion();
	for (int i=0; i<24; i++){
				switch(i){
					case 1: 
							obj_clean.cleaner_up();
							obj_hive.foul();
					break;
					case 2: 
							obj_clean.cleaner_up();
							obj_hive.foul();
					break;
					case 3: 
							obj_clean.cleaner_up();
							obj_hive.foul();
					break;
					case 4: 
							obj_clean.cleaner_up();
							obj_hive.foul();
							
					break;
					case 5: 
							obj_clean.cleaner_up();
							obj_hive.foul();
					break;
					case 6: 
							obj_clean.cleaner_up();
							obj_hive.foul();
					break;
					case 7: 
							obj_clean.cleaner_up();
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
					case 24: 
							obj_hive.foul();
					break;
				}
			}
			
	return 0;
}
