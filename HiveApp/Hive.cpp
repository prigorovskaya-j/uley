#include <iostream>
#include "Hive.h"

Hive::Hive()
{
	vosk = 0;
	graz = 0;
	med = 0;
	water = 0;
	nectar = 0;
	soty = 0;
	cout << "const_hive" << endl;
};

Hive::~Hive() {
	cout << "destr_hive" << endl;
	delete[] arr_hive;
};

void Hive::foul() { //������������
	graz += 1.5;
	cout << "graz=" << graz << endl;
};

void Hive:: initial_condtion() {
	/*cout << "enter max size: " << endl;
	cin >> size; */
	cout << "������� ��������� ���������� ����" << endl;
	cin >> med;
	cout << "������� ��������� ���������� ����" << endl;
	cin >> water;
	cout << "�������� ������� ��������� ���������� �������" << endl;
	cin >> nectar;
};