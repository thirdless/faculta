#include<iostream>
#include<conio.h>
#include<string.h>
#include "Header.h"

using namespace std;

void clrscr() {
	system("cls");
}

void pauza() {
	_getch();
}

ElementMeniu::ElementMeniu(const char* nume) {
	this->nume = new char[100];
	strcpy(this->nume, nume);
}

ElementMeniu::~ElementMeniu() {
	delete[] this->nume;
}

void ElementMeniu::afisareIncompletaTitlu() {
	if (parinte != NULL) {
		parinte->afisareIncompletaTitlu();
		cout << " -> " << nume;
	}
	else {
		cout << nume;
	}
}

void ElementMeniu::afisareTitlu() {
	afisareIncompletaTitlu();
	cout << ":" << endl << endl;
}

Operatie::Operatie(const char* nume) : ElementMeniu(nume) {}

void Operatie::executa() {
	clrscr();
	this->afisareTitlu();
	this->execOperatie();
}

Meniu::Meniu(const char* nume) : ElementMeniu(nume) {
	this->elemente = new ElementMeniu * [nrMaxElemente];
	this->nrElemente = 0;
}

Meniu::~Meniu() {
	for (int i = 0; i < nrElemente; i++) {
		delete elemente[i];
	}
	delete[] elemente;
}

/*returneaza indicele elementului activat, sau -1 pentru
iesire*/
int Meniu::citireComanda() {
	while (1) {
		char ch;
		cout << "Introduceti comanda:";
		ch = _getch();
		cout << endl;
		if (ch > '0' &&
			(ch - '0') <= this->nrElemente) {
			//element meniu
			int comanda = ch - '1';
			/*pt '1' va fi elementul 0*/
			return comanda;
		}
		else if (ch == '0' || ch == 0x1B) {
			/*0 sau ESC - iesire din meniu
			return -1;*/
		}
		else {
			//tasta invalida
			cout << "Tasta invalida: " << ch
				<< " Tastele valide sunt '0' - '"
				<< nrElemente << "'" << endl << endl;
		}
	}
}


void Meniu::adaugaElement(ElementMeniu* element) {
	nrElemente++;
	elemente[nrElemente - 1] = element;
	element->parinte = this;
}

void Meniu::afisare() {
	for (int i = 0; i < nrElemente; i++) {
		elemente[i]->afisareTitlu();
	}
}

void Meniu::executa() {
	for (;;) {
		int comanda;
		clrscr();
		afisareTitlu();
		afisare();
		comanda = citireComanda();
		if (comanda >= 0 &&
			comanda < nrElemente) {
			elemente[comanda]->executa();
		}
		else {
			//probabil iesirea - -1
			return;
		}
	}
}

OperatieAdunare::OperatieAdunare(const char* nume) : Operatie(nume) {}

Lista::Lista(int dim) {
	this->dim = dim;
	elem = new int[dim];
}
Lista::~Lista() {
	delete[] elem;
}
void Lista::operator+=(int num) {
	if (n == dim) {
		cout << "Lista plina" << endl;
	}
	else {
		elem[n] = num;
		n++;
	}
}

void Lista::operator+=(Lista& lst) {
	for (int i = 0, a = lst.getDim(); i < a; i++) {
		(*this) += lst.operator[](i);
	}
}

int Lista::operator[](int num) {
	if (num < n && n > 0) return elem[num];
	return NULL;
}

void Lista::sterge(int index) {
	for (int i = index; i < n - 1; i++) {
		elem[i] = elem[i + 1];
	}
	n--;
}
void Lista::afisare() {
	for (int i = 0; i < n; i++) {
		cout << i << ". " << elem[i] << endl;
	}
}

void OperatieAdunare::execOperatie() {
	int a, b;
	cout << "Introduceti 2 numere:";
	cin >> a >> b;
	cout << "suma = " << a + b << endl;
	pauza();
}

OperatieScadere::OperatieScadere(const char* nume) : Operatie(nume) {}

void OperatieScadere::execOperatie() {
	int a, b;
	cout << "Introduceti 2 numere:";
	cin >> a >> b;
	cout << "diferenta = " << a - b << endl;
	pauza();
}

OpAdaugaInLista::OpAdaugaInLista(const char* nume, Lista* lista) : Operatie(nume) {
	this->lista = lista;
}
void OpAdaugaInLista::execOperatie() {
	int num;
	cout << "num=";
	cin >> num;
	(*lista) += num;
	pauza();
}
OpAfisareLista::OpAfisareLista(const char* nume, Lista* lista) :
	Operatie(nume) {
	this->lista = lista;
}
void OpAfisareLista::execOperatie() {
	lista->afisare();
	pauza();
}

OpStergereLista::OpStergereLista(const char* nume, Lista* lista) : Operatie(nume) {
	this->lista = lista;
}

void OpStergereLista::execOperatie() {
	int num;
	cout << "index=";
	cin >> num;
	lista->sterge(num);
	pauza();
}

OpConcatLista::OpConcatLista(const char* nume, Lista* lista, Lista* lista2) :
	Operatie(nume) {
	this->lista = lista;
	this->lista2 = lista2;
}
void OpConcatLista::execOperatie() {
	(*lista) += (*lista2);
	pauza();
}

int Lista::getDim() {
	return n;
}

int main() {
	Meniu* meniu = new Meniu("Meniu Principal");
	Meniu* submeniuCalculator = new Meniu("Calculator");
	meniu->adaugaElement(submeniuCalculator);
	submeniuCalculator->adaugaElement(new OperatieAdunare("'+'"));
	submeniuCalculator->adaugaElement(new OperatieScadere("'-'"));

	Lista* lista = new Lista(10);
	Lista* lista2 = new Lista(10);

	Meniu* submeniuLista = new Meniu("Lista");
	meniu->adaugaElement(submeniuLista);
	submeniuLista->adaugaElement(new OpAdaugaInLista("'+ pt 1'", lista));
	submeniuLista->adaugaElement(new OpAdaugaInLista("'+ pt 2'", lista2));
	submeniuLista->adaugaElement(new OpStergereLista("'-'", lista));
	submeniuLista->adaugaElement(new OpAfisareLista("'Afisare'", lista));
	submeniuLista->adaugaElement(new OpConcatLista("'Concat'", lista, lista2));

	meniu->executa();

	delete meniu;

	cout << endl << endl << "Sfarsit." << endl;
	pauza();
	return 0;
}
