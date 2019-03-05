#include<iostream>
#include "grupa.h"

void InitGrupa(struct Grupa &grupa) {
	cout << "\nNumarul grupei: ";
	cin >> grupa.id;
	cout << "\nNumarul studentilor: ";
	cin >> grupa.nr;
	grupa.tab = new Student[grupa.nr];
	for (int i = 0; i < grupa.nr; i++){
		InitStudent(grupa.tab[i]);
	}
}

void AfisGrupa(struct Grupa grupa){
	cout << "\nStudentii grupei " << grupa.id << " sunt:";
	for (int i = 0; i < grupa.nr; i++){
		AfisStudent(grupa.tab[i]);
	}
}

void StergeGrupa(struct Grupa &grupa){
	for (int i = 0; i < grupa.nr; i++){
		StergeStudent(grupa.tab[i]);
	}
}