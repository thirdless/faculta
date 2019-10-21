#include "Catalog.h"

void Catalog::setComparator(PFnComparare comparator) {
	int i;
	for (int i = 0; i < nrGrupe; i++) {
		tabGrupe[i].comparator = comparator;
	}
}

void Grupa::elibMem(void) {
	int s;
	if (numeGrupa) {
		cout << "Eliberarea memoriei pentru grupa: " << numeGrupa << '\n' ;
		free(numeGrupa);
		numeGrupa = NULL;
	}
	for (int i = 0; i < nrStud; i++) {
		tabStudenti[i].elibMem();
	}
	free(tabStudenti);
	tabStudenti = NULL;
}

int comparNumeAlfabetic(Student a, Student b) {
	int rez = strcmp(a.getNume(), b.getNume());
	return rez;
}

int comparNoteDescrescator(Student a, Student b) {
	int rez = a.getNota() - b.getNota();
	if (rez > 0) rez = 1;
	else if (rez < 0) rez = -1;
	return rez;
}


int comparNumeDupaLungimeCrescator(Student a, Student b) {
	int rez = strlen(a.getNume()) - strlen(b.getNume());
	if (rez > 0) rez = 1;
	else if (rez < 0) rez = -1;
	return rez;
}

int Student::getNota(void) {
	return nota;
}

void Student::setNota(int a) {
	nota = a;
}

char * Student::getNume(void) {
	return nume;
}

void Student::setNume(char unNume[]) {
	nume = new char;
	strcpy(nume, unNume);
}

void Student::elibMem(void) {
	free(nume);
}

void Student::citire(void) {
	char buff[50];
	int n;

	cout << "\nNume student: ";
	cin.ignore(100, '\n');
	cin.getline(buff, 50);
	setNume(buff);

	cout << "Nota student: ";
	cin >> n;
	setNota(n);
}

void Student::afisare(void) {
	cout << "\nNume student: " << nume << "\nNota student: " << nota << "\n\n";
}

void Grupa::citire(void) {
	int n;
	char buff[50];

	cout << "\nNume grupa: ";
	cin.ignore(100, '\n');
	cin.getline(buff, 50);
	
	numeGrupa = new char;
	strcpy(numeGrupa, buff);

	cout << "Numar studenti: ";
	cin >> nrStud;

	tabStudenti = new Student[nrStud];

	for (int i = 0; i < nrStud; i++) {
		tabStudenti[i].citire();
	}
}

void Grupa::afisare(void) {
	cout << "\nGrupa " << numeGrupa << " cu " << nrStud << " studenti contine:\n";
	for (int i = 0; i < nrStud; i++) {
		tabStudenti[i].afisare();
	}
}

void swap2(Student &a, Student &b) {
	Student aux;

	aux.setNota(a.getNota());
	aux.setNume(a.getNume());

	a.setNota(b.getNota());
	a.setNume(b.getNume());

	b.setNota(aux.getNota());
	b.setNume(aux.getNume());
}

void Grupa::bSort(void) {
	int suntPerm = 1;
	while (suntPerm) {
		suntPerm = 0;
		for (int i = 0; i < nrStud - 1; i++) {
			if (comparator(tabStudenti[i], tabStudenti[i + 1])) {
				swap2(tabStudenti[i], tabStudenti[i + 1]);
				suntPerm = 1;
			}
		}
	}
}

void Catalog::citire(void) {
	cout << "\nNumar grupe: ";
	cin >> nrGrupe;
	
	tabGrupe = new Grupa[nrGrupe];

	for (int i = 0; i < nrGrupe; i++) {
		tabGrupe[i].citire();
	}
}

void Catalog::afisare(void) {
	cout << "\n----------------------------------------------";
	for (int i = 0; i < nrGrupe; i++) {
		tabGrupe[i].afisare();
	}
}

void Catalog::sortare(void) {
	for (int i = 0; i < nrGrupe; i++) {
		tabGrupe[i].bSort();
	}
}

void Catalog::elibMem(void) {
	delete[] tabGrupe;
}