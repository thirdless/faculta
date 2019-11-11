#include<iostream>
using namespace std;

class Complex {
		int re, im;
	public:
		Complex();
		Complex(int, int);
		Complex operator + (Complex);
		Complex operator * (Complex);
		Complex operator - (Complex);
		bool operator == (Complex);
		Complex& operator=(const Complex &src);
		Complex operator ~ ();
		void afisare();
		void citire();
};

Complex::Complex() {
}

Complex::Complex(int re, int im) {
	this->re = re;
	this->im = im;
}


Complex Complex::operator+(Complex c2) {
	Complex temp;
	temp.re = this->re + c2.re;
	temp.im = this->im + c2.im;
	return temp;
}

Complex Complex::operator-(Complex c2) {
	Complex temp;
	temp.re = c2.re - this->re;
	temp.im = c2.im - this->im;
	return temp;
}


Complex& Complex::operator=(const Complex &src) {
	this->re = src.re;
	this->im = src.im;
	return *this;
}

Complex Complex::operator*(Complex c2) {
	Complex temp;
	temp.re = c2.re * this->re;
	temp.im = c2.im * this->im;
	return temp;
}

Complex Complex::operator~() {
	Complex temp;
	temp.re = this->re;
	temp.im = 0;
	return temp;
}

bool Complex::operator==(Complex c2) {
	if (c2.re == this->re && c2.im == this->im) return true;
	return false;
}

void Complex::afisare() {
	cout << "(" << re << "," << im << ")" << endl;
}

void Complex::citire() {
	cout << "re = ";
	cin >> re;
	cout << "im = ";
	cin >> im;
}

int main() {
	Complex a(0, 0);
	Complex b(0, 0);
	Complex c;
	a.citire();
	b.citire();
	c = a - b;
	c.afisare();
	c = a * b;
	c.afisare();
	cout << (a == b) << endl;
	c = ~a;
	c.afisare();
	system("pause");
	return 0;
}
