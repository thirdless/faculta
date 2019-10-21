#include "Catalog.h"


int main(void) {
	int operatie = -1;
	PFnComparare cevapointer;
	Catalog catalogAn1, catalogAn2, catalogAn3, catalogAn4;
	Catalog catalogMaster[2];

	catalogAn2.citire();
	catalogAn2.afisare();

	do {
		do {
			cout << "Ce doriti sa efectuati?" << endl;
			cout << "0.Iesire din program;" << endl;
			cout << "1 - sortare alfabetica a numelor;" << endl;
			cout << "2 - sortare descrescatoare dupa nota;" << endl;
			cout << "3 - sortare dupa lungimea numelui - crescator." << endl;
			cin >> operatie;
		} while ((operatie<0) || (operatie>3));
		switch (operatie)
		{
		case 1:
			cout << "1 - sortare alfabetica a numelor;" << endl;
			cevapointer = comparNumeAlfabetic;
			catalogAn2.setComparator(cevapointer);
			break;
		case 2:
			cout << "2 - sortare descrescatoare dupa nota;" << endl;
			cevapointer = comparNoteDescrescator;
			catalogAn2.setComparator(cevapointer);
			break;
		case 3:
			cout << "3 - sortare dupa lungimea numelui - crescator." << endl;
			cevapointer = comparNumeDupaLungimeCrescator;
			catalogAn2.setComparator(cevapointer);
			break;
		default:
			cout << "Sfarsitul executiei programului." << endl;

			catalogAn2.elibMem();

			return 0;
		}
		catalogAn2.sortare();
		catalogAn2.afisare();
	} while (operatie);
	

}
