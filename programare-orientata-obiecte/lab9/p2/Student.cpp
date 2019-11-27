#include<iostream>
#include<string.h>
#include "Persoana.h"
#include "Student.h"
using namespace std;

StudentAC::StudentAC()
{
	cout << "constr. fara arg. StudentAC" << endl;
	m_ianStudiu = 0;
	m_inotaP2 = 0;
}
StudentAC::StudentAC(string cnp, string nume, string adresa,
	int anStudiu, int notaP2) :
	PersoanaAC(cnp, nume, adresa), m_ianStudiu(anStudiu),
	m_inotaP2(notaP2)
{
	cout << "constr. cu arg. StudentAC" << endl;
}
StudentAC::~StudentAC()
{
	cout << "destructor StudentAC" << endl;
}

void StudentAC::afisareProfil() {
	PersoanaAC::afisareProfil();
	cout << "\nAn studiu " << m_ianStudiu;
	cout << "\nNota P2  " << m_inotaP2;
}

void StudentAC::inscriereAnStudiu(int anStudiuNou) {
	m_ianStudiu = anStudiuNou;
}

int StudentAC::getAn() {
	return m_ianStudiu;
}

int StudentAC::getNota() {
	return m_inotaP2;
}

StudentAC* StudentAC::compara(StudentAC * s1) {
	if (this->getNota() > s1->getNota()) return this;
	else return s1;
}

StudentMaster::StudentMaster(string cnp, string nume, string adresa, int an, int nota, string NumeD) : StudentAC(cnp, nume, adresa, an, nota) {
	cout << "Constructor StudentMaster\n";
	m_sNumeDis = NumeD;
}

StudentMaster::~StudentMaster() {
	cout << "destructor master";
}

void StudentMaster::afisareProfil() {
	StudentAC::afisareProfil();
	cout << "\nNume Disertatie " << m_sNumeDis.data() << endl;
}