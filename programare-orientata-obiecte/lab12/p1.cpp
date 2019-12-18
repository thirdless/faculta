#include<iostream>
using namespace std;

template <typename T>
void afisare(T v[], int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
void sortare(T v[], int n) {
	T aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

int main() {
	int veci[10] = {1,5,3,8,6,7,4,2,10,9},
		n = 10;
	float vecf[10]= {4.2f,1.2f,10.2f, 6.2f, 2.2f, 3.2f, 9.2f, 7.2f, 5.2f, 8.2f};

	sortare<int>(veci, n);
	sortare<float>(vecf, n);
	afisare<int>(veci, n);
	afisare<float>(vecf, n);
	system("pause");
	return 0;
}
