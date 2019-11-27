#include<iostream>
#include<string.h>
#include "Persoana.h"
#include "Student.h"
using namespace std;

void afisareProfil(StudentAC * s1) {
	cout << "CNP" << s1->getCNP().data();
	cout << "Nume " << s1->getNume().data();
	cout << "Adresa " << s1->getAdresa().data();
	cout << "An studiu " << s1->getAn();
	cout << "Nota P2 " << s1->getNota();
}

StudentMaster* notamax(StudentMaster a[], int length) {
	StudentMaster* max = &a[0];
	for (int i = 1; i < length; i++) {
		if (a[i].getNota() > max->getNota()) max = &a[i];
	}
	return max;
}

int main()
{
	StudentMaster a[3] = { {"123123123", "Ana", "Iasi", 2, 10, "Dizertatie123"}, {"312321321123", "Maria", "Bucuresti", 3, 9, "Cea mai fabuloasa dizertatie"}, {"414124131", "Ioana", "Cluj", 1, 6, "Nume creativ de dizertatie"} };
	(notamax(a, 3))->afisareProfil();
	system("pause");
	return 0;
}
