#include<conio.h>
#include<iostream>

using namespace std;

class Multime {
	private:
		int * data;
		int dim;
		int n;
	public:
		Multime();
		Multime(int D);
		void adauga(int x);
		void extrage(int x);
		void afisare();
		~Multime();
};

Multime::Multime() {
	cout << "Introduceti lungimea: ";
	cin >> dim;
	if (data) delete[] data;
	data = new int[dim];
	n = 0;
}

Multime::Multime(int D) {
	dim = D;
	if (data) delete[] data;
	data = new int[dim];
	n = 0;
}

Multime::~Multime() {
	delete[] data;
	data = nullptr;
	n = 0;
}

void swap(int data[], int dim, int n) {
	for (int i = n; i < dim - 1; i++) {
		data[i] = data[i + 1];
	}
}

void Multime::adauga(int x) {
	if (n == dim) cout << "FULL";
	else {
		int OK = 1;
		for (int i = 0; i < n; i++) {
			if (data[i] == x) {
				OK = 0;
			}
		}
		if (OK == 1) {
			data[n] = x;
			n++;
		}
	}
}

void Multime::extrage(int x) {
	
	int OK = 0;
	for (int i = 0; i < n; i++) {
		if (data[i] == x) {
			swap(data, n, i);
			n--;
			OK = 1;
		}
	}
	if (OK == 0) {
		cout << "Valoarea nu a fost gasita" << endl;
	}

}

void Multime::afisare() {
	for (int i = 0; i < n; i++) cout << data[i] << " ";
	cout << endl;
}



int main() {
	Multime m(10);
	m.adauga(4);
	m.adauga(3);
	m.afisare();
	m.extrage(4);
	m.extrage(4);
	m.afisare();
	m.adauga(9);
	m.adauga(2);
	m.adauga(2);
	m.afisare();
	_getch();
	return 0;
}
