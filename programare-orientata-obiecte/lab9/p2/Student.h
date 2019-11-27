#pragma once

#include "Persoana.h"

class StudentAC : public PersoanaAC
{
	int m_ianStudiu;
	int m_inotaP2;
public:
	StudentAC();
	StudentAC(string cnp, string nume, string adresa, int
		anStudiu, int notaP2);
	~StudentAC();
	void afisareProfil();
	void inscriereAnStudiu(int anStudiuNou);
	int getAn();
	int getNota();
	StudentAC* compara(StudentAC * s1);
};

class StudentMaster : public StudentAC {
	string m_sNumeDis;
public:
	StudentMaster(string cnp, string nume, string adresa, int an, int nota, string NumeD);
	~StudentMaster();
	void afisareProfil();
};