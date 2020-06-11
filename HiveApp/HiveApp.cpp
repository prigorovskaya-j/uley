#include <iostream>
#include "Hive.h"
#include "Cleaner.h"
#include "Builder.h"
#include "Queen.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Hive* hive = new Hive();
	Cleaner* cleaner = new Cleaner(hive);
	Builder* builder = new Builder(hive);
	Queen* queen = new Queen(hive);

	hive->initialCondtion();

	for (int i = 0; i < 23; i++) {
		cleaner->checkingDeath();
		builder->checkingDeath();
		queen->checkingDeath();
		switch (i) {
		case 0:

			hive->foul();
			cleaner->Test();
			cleaner->cleanerUp();
			builder->build();
			break;
		case 1:

			hive->foul();
			cleaner->cleanerUp();
			builder->build();
			break;
		case 2:

			hive->foul();
			cleaner->cleanerUp();
			builder->build();
			break;
		case 3:
			hive->foul();
			cleaner->cleanerUp();
			builder->build();

			break;
		case 4:
			hive->foul();
			cleaner->cleanerUp();
			builder->build();
			break; 
		case 5:
			hive->foul();
			cleaner->cleanerUp();
			builder->buildHoneycombs();
			break;
		case 6:
			hive->foul();
			cleaner->cleanerUp();
			builder->build();
			break;
		case 7:
			hive->foul();
			builder->build();
			break;
		case 8:
			hive->foul();
			break;
		case 9:
			hive->foul();
			break;
		case 10:
			hive->foul();
			break;
		case 11:
			hive->foul();
			break;
		case 12:
			hive->foul();
			break;
		case 13:
			hive->foul();
			break;
		case 14:
			hive->foul();
			break;
		case 15:
			hive->foul();
			break;
		case 16:
			hive->foul();
			break;
		case 17:
			hive->foul();
			break;
		case 18:
			hive->foul();
			break;
		case 19:
			hive->foul();
			break;
		case 20:
			hive->foul();
			break;
		case 21:
			hive->foul();
			break;
		case 22:
			hive->foul();
			break;
		case 23:
			hive->foul();
			break;

		};
	};
	system("pause");
	
	delete hive;
	delete cleaner;
	
	return 0;
}