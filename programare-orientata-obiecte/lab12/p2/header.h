#pragma once

template <typename T>
class Multime {
	T * m;
	int n;
public:
	Multime() {
		n = 0;
		m = new T[1024];
	}
	Multime(T * v, int p) {
		m = new T[1024];
		for (int i = 0; i < p; i++) {
			m[i] = v[i];
		}
		n = p;
	}
	Multime(Multime& xd) {
		m = new T[1024];
		for (int i = 0; i < xd.n; i++) {
			m[i] = xd.m[i];
		}
		n = xd.n;
	}
	~Multime() {
		delete[] m;
	}
	T operator!() {
		T max = m[0];
		for (int i = 1; i < n; i++) {
			if (m[i] > max) max = m[i];
		}
		return max;
	}
	Multime& operator+(Multime& xd) {
		int max = n < xd.n ? n : xd.n;
		for (int i = 0; i < max; i++) {
			m[i] += xd.m[i];
		}
		return *this;
	}
	Multime& operator=(Multime& xd) {
		n = xd.n;
		for (int i = 0; i < n; i++) {
			m[i] = xd.m[i];
		}
		return *this;
	}
	void afisare() {
		for (int i = 0; i < n; i++) {
			cout << m[i] << " ";
		}
		cout << endl;
	}
};

template <typename T>
T aduna(T a, T b) {
	return a + b;
}
