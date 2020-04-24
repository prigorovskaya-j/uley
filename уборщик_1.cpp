#include <iostream>

using namespace std; 

//поле
class Area{
	protected: 
		int hive[]; //улей
		int flovers[];
};


class Hive{
	protected: 
		int bees[];
		double graz;
		double med;
		int water;
	
	public:
		Hive(){
			graz=0;
			cout<<"const_bees"<<endl;
		};
		~Hive(){
			cout<<"destr_hive"<<endl;
		};
		void initial_condtion(){
			cout<<"¬ведите начальное количество меда"<<endl;
			cin>>med;
			cout<<"¬ведите начальное количество воды"<<endl;
			cin>>water;
		};
		void foul(){ //загр€зн€тьс€
			graz=graz+1.5;
		};
		
		void build(){ 
		};
		void divide(){ //делитьс€
		};
};


class Bees{
	
	protected: 
		int age;
		double sitost;
		int energy;
		double drink;
	
	public:
		Bees(){
			sitost=25;
			energy=110;
			drink=25;
			cout<<"const_bees"<<endl;
		};
		~Bees(){
			cout<<"destr_bees"<<endl;
		};
		void otdih(){
			//for(int i=0;i<7; i++){
				energy+=15;
				cout<<"energy+15"<<endl;
			//}
		};
		
//		virtual void eat_pok()=0;
		
		virtual void eat_akt()=0;
		
		void drinking(){
			drink+=0.2;
			cout<<"drink +0.2"<<endl;
		};
		die(){
		};
};


class Cleaner: public Bees, Hive{

	public:
	
	void eat_akt(){
		Hive::med-=0.3;
		sitost+=0.3;
		cout<<"sitost +0.3; med -0.3"<<endl;
	};
	void cleaner_up(){
			for (int i=0; i<60; i+=15){
			if(Hive::graz!=0){
					Hive::graz--;
					sitost-=0.3;
					drink-=0.2;
					energy-=6;
					cout<<"graz -1; sitost -0.3; drink -0.2; energy -6"<<endl;
				
			} else if (sitost<25){
							eat_akt();
							drink-=0.2;
							energy-=6;
							cout<<"drink -0.2; energy -6"<<endl;
					} else if(drink<25){
								drinking();
							} else if(energy<110){ 
								otdih();
								sitost-=0.2;
								drink-=0.2;
								cout<<"sitost -0.2; drink -0.2"<<endl;
							}
			}
									
		};
};



int main(){
	setlocale(LC_ALL, "rus");
	
	Cleaner obj_clean;
	Hive obj_hive;
	
	obj_hive.initial_condtion();
	

		for (int i=0; i<23; i++){
		
				switch(i){
						system("pause");
					case 0: 
							obj_hive.foul();
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
