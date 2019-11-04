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

Complex::Complex(int re, int im) {
	this->re = re;
	this->im = im;
}

int Complex::egal(Complex c2) {
	if (this->re == c2.re && this->im == c2.im) return 1;
	else return 0;
}

void Complex::citire() {
	cout << "re = "; cin >> this->re;
	cout << "im = "; cin >> this->im;
}

int main() {
	Complex c1(1,2);
	Complex c2(1,2);
	c1.citire();
	c2.citire();
	cout << c1.egal(c2);
	system("pause");
	return 0;
}
