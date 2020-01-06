#include<iostream>
#include<string>
using namespace std;

int uppercase(string h) {
	int count = 0;
	for (int i = 0; i < size(h); i++) {
		if (h[i] >= 'A' && h[i] <= 'Z') count++;
	}
	return count;
}

int digits(string h) {
	string::iterator s;
	int count = 0;
	for (s = h.begin(); s != h.end(); s++) {
		if (*s >= '0' && *s <= '9') count++;
	}
	return count;
}

int main() {
	string j = "Lol123";
	cout << uppercase(j) << " ";
	cout << digits(j) << " ";
	system("pause");
	return 0;
}
