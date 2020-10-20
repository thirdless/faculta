#include<iostream>
using namespace std;

double TSm, O;

double genExp(double lambda)
{
	double u, x;
	u = (double)rand() / (RAND_MAX + 1);
	x = -1 / lambda * log(1 - u);
	return x;
}

double genGauss(double medie, double sigma) {
	double s = 0;
	int i;

	for (i = 1; i <= 12; i++) {
		s += (double)rand() / (RAND_MAX + 1);
	}

	return medie + sigma * (s - 6);
}

void sistem(long int NS, int lambda, int mu) {
	double STP = 0, STS = 0, STL = 0, Ta = 0;
	int i = 1;

	while (i <= NS) {
		double Tp = genExp(mu);
		STP += Tp;

		STS += Ta + Tp;
		double Dis = genExp(lambda);

		if (Dis > Ta + Tp) {
			STL += Dis - (Ta + Tp);
			Ta = 0;
		}
		else {
			Ta = Ta + Tp - Dis;
		}

		i++;
	}

	TSm = STS / NS;
	O = STP / (STP + STL) * 100;

}

void sistem2(long int NS, int lambda, int mu, double sigma) {
	double STP = 0, STS = 0, STL = 0, Ta = 0;
	int i = 1;

	while (i <= NS) {
		double Tp = genGauss(1.0f/mu, sigma);
		STP += Tp;

		STS += Ta + Tp;
		double Dis = genExp(lambda);

		if (Dis > Ta + Tp) {
			STL += Dis - (Ta + Tp);
			Ta = 0;
		}
		else {
			Ta = Ta + Tp - Dis;
		}

		i++;
	}

	TSm = STS / NS;
	O = STP / (STP + STL) * 100;

}

int main() {
	for (int i = 4; i < 10; i++) {
		sistem(1000000, i, 10);
		cout << "Lambda = " << i << "; TSm = " << TSm << "; O = " << O << "%; " << endl;
	}
	cout << endl << endl;
	for (int i = 4; i < 10; i++) {
		sistem2(1000000, i, 10, 0.01);
		cout << "Lambda = " << i << "; TSm = " << TSm << "; O = " << O << "%; " << endl;
	}
}