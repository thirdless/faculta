#include<iostream>
#include "Header.h"
using namespace std;

void student_CPP::Read(void) {
	cout << "Numar matricol: ";
	cin >> nrMatricol;
	cout << "Nume elev: ";
	cin.ignore(100, '\n');
	cin.getline(nume, 100);
	cout << "Gen: ";
	cin >> gen;
	cout << "Nota: ";
	cin >> nota;
	cout << endl;
}

void student_CPP::Write(void) {
	cout << "Numar matricol: " << nrMatricol << "\nNume elev: " << nume << "\nGen: " << gen << "\nNota: " << nota << "\n\n";
}

int main(void) {
	int n;
	cout << "Numar studenti: ";
	cin >> n;
	student_CPP * student = new student_CPP[n];

	for (int i = 0; i < n; i++) student[i].Read();
	for (int i = 0; i < n; i++) student[i].Write();

	delete []student;
	system("pause");
	return 0;
}