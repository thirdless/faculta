#include<iostream>
#include "Header.h"
using namespace std;

int main(void) {
	int n;
	cout << "Nr studenti: ";
	cin >> n;
	student_C * student = new student_C[n];
	
	for (int i = 0; i < n; i++) {
		student[i].read = ReadData;
		student[i].write = WriteData;

		student[i].read(&student[i]);
	}

	for (int i = 0; i < n; i++) student[i].write(&student[i]);

	delete []student;

	system("pause");

	return 0;
}
