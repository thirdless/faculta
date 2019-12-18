#include<iostream>
#include "Header.h"
using namespace std;

int main() {
	int a[3] = { 1,3,2 };
	int b[5] = { 6,2,3,9,1 };
	Multime<int> m1(a, 3);
	Multime<int> m4(b, 5);
	m1.afisare();
	Multime<int>m2 = m1;
	m2.afisare();
	Multime<int>m3;
	m3 = m1 + m4;
	cout << "====" << endl;
	m1.afisare();
	m2.afisare();
	m3.afisare();
	cout << !m3 << endl;
	system("pause");
	return 0;
}
