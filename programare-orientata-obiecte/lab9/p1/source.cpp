#include<iostream>
#include<string.h>
#include "Persoana.h"
#include "Student.h"
using namespace std;

int main()
{
	PersoanaAC p1("1234567890123", "Ana", "Iasi");
	p1.afisareProfil();
	StudentAC s2;
	s2.afisareProfil();
	StudentAC s1("1234567890122", "Ion", "Vaslui", 2, 10);
	s1.schimbareAdresa("Bucuresti");
	s1.inscriereAnStudiu(3);
	s1.afisareProfil();
	//system("pause");
	return 0;
}
