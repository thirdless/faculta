#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Masina {
	char *marca, *culoare;
	double pret, vitezaMaxima;
public:
	Masina(char * marca1, char * culoare1, double pret1, double viteza);
	double getViteza();
	double getPret();
	char * getNume();
	bool operator<(Masina s);
};

Masina::Masina(char * marca1, char * culoare1, double pret1, double viteza) {
	marca = new char[strlen(marca1) + 1];
	strcpy(marca, marca1);
	culoare = new char[strlen(culoare1) + 1];
	strcpy(culoare, culoare1);
	pret = pret1;
	vitezaMaxima = viteza;
}

double Masina::getViteza() {
	return vitezaMaxima;
}

double Masina::getPret() {
	return pret;
}

char* Masina::getNume() {
	return marca;
}

bool Masina::operator<(Masina s) {
	if (this->getViteza() == s.getViteza()) return this->getPret() < s.getPret() ? true : false;
	return this->getViteza() < s.getViteza() ? true : false;
}

void afisare(vector<Masina> v) {
	for (vector<Masina>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << it->getNume() << " " << it->getPret() << " " << it->getViteza();
		cout << endl;
	}
}

bool compare(Masina s1, Masina s2) {
	if (s1 < s2)
		return false;
	else
		return true;
}

int main() {
	Masina v[] = {
		{ "Suzuki", "Alb", 1500, 130 },
		{"Nissan", "Verde", 1200, 120},
		{"Mitsubishi", "Negru", 1300, 120}
		
	};
	std::vector<Masina> h(v, v + 3);
	make_heap(h.begin(), h.end(), compare);
	sort_heap(h.begin(), h.end(), compare);
	afisare(h);
	system("pause");
	return 0;
}
