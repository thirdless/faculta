#pragma once

#include<iostream>
#include<string.h>
using namespace std;

class PersoanaAC
{
protected:
	string m_sCnp;
	string m_sNume;
	string m_sAdresa;
public:
	PersoanaAC();
	PersoanaAC(string cnp, string nume, string adresa);
	~PersoanaAC();
	void afisareProfil();
	void schimbareAdresa(string adresaNoua);
};