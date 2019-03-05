#include<iostream>
#include "student.h"
using namespace std;

void InitStudent(struct Student &student){
	student.nume = new char[50];
	cout << "\nNumele elevului: ";
	getchar();
	cin.getline(student.nume, 50);
	cout << "\nNota elevului: ";
	cin >> student.nota;
}

void AfisStudent(struct Student student) {
	cout << "\nNumele elevului este " << student.nume << " iar nota lui este " << student.nota;
}

void StergeStudent(struct Student &student){
	delete[] student.nume;
}
