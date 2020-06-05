#include <iostream>
#include "Hive.h"
#include "Cleaner.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Hive* hive = new Hive();
	Cleaner* cleaner = new Cleaner(hive);

	hive->Initialise();

	for (int i = 0; i < 23; i++) {

		switch (i) {
		case 0:
			hive->Pollute();
			cleaner->Test();
			cleaner->Up();
			break;
		case 1:

			hive->Pollute();
			cleaner->Up();
			break;
		case 2:

			hive->Pollute();
			cleaner->Up();
			break;
		case 3:
			hive->Pollute();
			cleaner->Up();

			break;
		case 4:
			hive->Pollute();
			cleaner->Up();
			break;
		case 5:
			hive->Pollute();
			cleaner->Up();
			break;
		case 6:
			hive->Pollute();
			cleaner->Up();
			break;
		case 7:
			hive->Pollute();
			break;
		case 8:
			hive->Pollute();
			break;
		case 9:
			hive->Pollute();
			break;
		case 10:
			hive->Pollute();
			break;
		case 11:
			hive->Pollute();
			break;
		case 12:
			hive->Pollute();
			break;
		case 13:
			hive->Pollute();
			break;
		case 14:
			hive->Pollute();
			break;
		case 15:
			hive->Pollute();
			break;
		case 16:
			hive->Pollute();
			break;
		case 17:
			hive->Pollute();
			break;
		case 18:
			hive->Pollute();
			break;
		case 19:
			hive->Pollute();
			break;
		case 20:
			hive->Pollute();
			break;
		case 21:
			hive->Pollute();
			break;
		case 22:
			hive->Pollute();
			break;
		case 23:
			hive->Pollute();
			break;

		};
	};
	system("pause");
	
	delete hive;
	delete cleaner;
	
	return 0;
}