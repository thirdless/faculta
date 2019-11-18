#include"Data.h"
#include"Persoana.h"
#include<iostream>


class Angajat : public Persoana {
private:
	Data *dataAngajare;
	int salariu;
public:
	Angajat(char *nume, char *prenume, Data * dataNastere, Data * angajare, int salariul);
	Data* getDataAngajare();
	int getSalariu();
	int getVarstaAnagajare();
	void afisarePerioadaMuncita(Data &dataCurenta);
	void afisare();
	~Angajat();
};

Angajat::Angajat(char *nume, char *prenume, Data *dataNastere, Data *angajare, int salariul):Persoana(nume, prenume, dataNastere){
	dataAngajare = angajare;
	salariu = salariul;
}

Data* Angajat::getDataAngajare() {
	return dataAngajare;
}

int Angajat::getSalariu() {
	return salariu;
}

int Angajat::getVarstaAnagajare() {
	return (getDataNastere()->getAn() - dataAngajare->getAn());
}

void Angajat::afisarePerioadaMuncita(Data &dataCurenta) {
	std::cout << (dataCurenta.getAn() - dataAngajare->getAn()) << "." << (dataCurenta.getLuna() - dataAngajare->getLuna()) << "." << (dataCurenta.getZi() - dataAngajare->getZi());
}

int main() {
	Data d(2000, 5, 19);
	Data d1(1997, 1, 3);
	Data d2(1990, 8, 29);
	Data a(2019, 3, 20);
	Data a1(2017, 4, 15);
	Data a2(2005, 10, 5);
	Angajat angajati[3] = { {"Radu", "Vasile", &d, &a, 1200}, {"Marian", "Gheorghe",&d1,&a1, 2500}, {"Mihnea", "Iulian",&d2 , &a2, 4000} };
	for (int i = 0; i < 3; i++) {
		{
			Data curent(2019, 11, 18);
			angajati[i].getVarstaAnagajare();
			angajati[i].afisarePerioadaMuncita(curent);
			angajati[i].afisare();
		}
	}
	return 0;
}
