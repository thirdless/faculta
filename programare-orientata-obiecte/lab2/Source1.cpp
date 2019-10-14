#include<iostream>
#include "Header.h"
using namespace std;

void ReadData(student_C * st) {
	cout << "Nr matricol: ";
	cin >> st->nrMatricol;
	cout << "Nume student: ";
	cin.ignore(100, '\n');
	cin.getline(st->nume, 100);
	cout << "Gen: ";
	cin >> st->gen;
	cout << "Nota student: ";
	cin >> st->nota;
	cout << endl;
}

void WriteData(student_C * st) {
	cout << "Numar matricol: " << st->nrMatricol << "\nNume student: " << st->nume << "\nGen: " << st->gen << "\nNota: " << st->nota << endl << endl;
}