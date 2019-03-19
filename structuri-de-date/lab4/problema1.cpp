#include<iostream>
using namespace std;

struct lista {

	lista * next, *prev;
	int data;

};

void insert(lista * &cap, int data) {
	lista * nou = new lista;
	nou->prev = NULL;
	nou->next = cap;
	nou->data = data;
	cap = nou;
}

void show(lista * cap) {
	while (cap != NULL) {
		cout << cap->data << " ";
		cap = cap->next;
	}
}

void insertafterpos(lista * &obiect, int pos, int data) {
	int increment = 0;
	lista * nou = new lista;
	lista * cap = obiect;
	lista * pozitie;
	nou->data = data;
	nou->next = NULL;
	nou->prev = NULL;
	while (true) {
		if (cap == NULL) break;
		else if (increment == pos) {
			pozitie = cap;
			cap = nou;
			cap->next = pozitie;
			cap->prev = pozitie->prev;
			pozitie->prev = cap;
			break;
		}
		increment++;
		cap = cap->next;
	}
}

void stergerepos(lista * &obiect, int pos) {
	int increment = 0;
	lista * pozitie;
	lista * cap = obiect;
	while (true) {
		if (cap == NULL) break;
		else if (pos == increment) {
			if (cap->prev != NULL) {
				pozitie = cap->prev;
				cap->prev = NULL;
				if (pozitie->prev != NULL) {
					(pozitie->prev)->next = cap;
					cap->prev = pozitie->prev;
				}
				delete pozitie;
				pozitie = NULL;
			}
			break;
		}
		increment++;
		cap = cap->next;
	}
}

int main() {
	int temp, alt_numar, pozitie;
	lista * cap = NULL;

	while (true) {
		cin >> temp;
		if (temp == 0) break;
		insert(cap, temp);
	}
	cout << "Lista citita este:\n";
	show(cap);

	cout << "\nSa se precizeze un numar care doriti sa intre in lista: ";
	cin >> alt_numar;

	cout << "Si pozitia din lista: ";
	cin >> pozitie;

	insertafterpos(cap, pozitie, alt_numar);

	show(cap);

	system("pause");

	cin >> temp;
	stergerepos(cap, temp);

	show(cap);
	system("pause");
}
