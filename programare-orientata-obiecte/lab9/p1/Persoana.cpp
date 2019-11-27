#include<iostream>
#include<string.h>
#include "Persoana.h"
#include "Student.h"
using namespace std;
PersoanaAC::PersoanaAC()
{
	cout << "constr. fara arg. PersoanaAC" << endl;
	m_sCnp = string(13, '0');
	m_sNume = "";
	m_sAdresa = "";
}
PersoanaAC::PersoanaAC(string cnp, string nume, string adresa)
{
	cout << "constr. cu arg. PersoanaAC" << endl;
	m_sCnp = cnp;
	m_sNume = nume;
	m_sAdresa = adresa;
}
PersoanaAC::~PersoanaAC()
{
	cout << "destructor PersoanaAC" << endl;
}void PersoanaAC::afisareProfil() {	cout << "CNP " << m_sCnp.data();	cout << "Nume " << m_sAdresa.data();	cout << "Adresa " << m_sNume.data();}void PersoanaAC::schimbareAdresa(string adresaNoua) {	m_sAdresa = adresaNoua;}