#include<conio.h>
#include<iostream>

using namespace std;

class Complex {
	int re, im;
public:
	Complex();
	Complex(int re, int im);
	int egal(Complex c2);
	void afisare();
	void citire();
};
Complex::Complex() {
	this->re = 0;
	this->im = 0;
}

Complex::Complex(int re, int im) {
	this->re = re;
	this->im = im;
}

int Complex::egal(Complex c2) {
	if (this->re == c2.re && this->im == c2.im) return 1;
	else return 0;
}

void Complex::afisare() {
	cout << "(" << re << "," << im << ")" << endl;
}


void Complex::citire() {
	cout << "re = "; cin >> this->re;
	cout << "im = "; cin >> this->im;
}

class MultimeComplexe {
	Complex * v;
	int dim;
	int n;
public:
	MultimeComplexe();
	void adauga(Complex a);
	void extrage(Complex a);
	void afisare();
	~MultimeComplexe();
};

MultimeComplexe::MultimeComplexe() {
	dim = 1024;
	n = 0;
	v = new Complex[dim];
}

MultimeComplexe::~MultimeComplexe() {
	dim = 0;
	n = 0;
	delete[] v;
}

void MultimeComplexe::extrage(Complex a) {
	int ok = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].egal(a)) {
			//n--;
			//v[i] = nullptr;
			while (i < n - 1) {
				v[i] = v[i + 1];
				i++;
			}
			n--;
			break;
		}
	}
}

void MultimeComplexe::adauga(Complex a) {
	int ok = 1;
	for (int i = 0; i < n; i++) {
		if (v[i].egal(a)) {
			ok = 0;
			break;
		}
	}
	if (ok) {
		v[n] = a;
		n++;
	}
}

void MultimeComplexe::afisare() {
	for (int i = 0; i < n; i++) {
		v[i].afisare();
	}
	cout << endl;
}

int main() {

	MultimeComplexe m;

	int temp = -1;

	while (temp != 0) {
		cout << "Alegeti actiune: 0 -iesire, 1 -adaugare, 2 -extragere\n";
		cin >> temp;
		switch (temp) {
		case 0:
			system("pause");
			return 0;
			break;
		case 1:
		{
			Complex temp;
			temp.citire();
			m.adauga(temp);
			m.afisare();
			break;
		}
		case 2:
		{
			Complex temp;
			temp.citire();
			m.extrage(temp);
			m.afisare();
			break;
		}
		};
	}
	system("pause");
	return 0;
}
