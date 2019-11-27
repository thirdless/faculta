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
	cout << "An studiu " << m_ianStudiu;
	cout << "Nota P2  " << m_inotaP2;
}

void StudentAC::inscriereAnStudiu(int anStudiuNou) {
	m_ianStudiu = anStudiuNou;
}