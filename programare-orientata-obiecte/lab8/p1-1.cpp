#pragma warning(disable : 4996)
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

int n = 0;

class Persoana {
protected:
	char nume[20], prenume[20];
public:
	void setValoriPersoana(char nume[], char
		prenume[]);
	void afisare();
};
class Student : public Persoana {
private:
	int grupa;
public:
	void setValoriStudent(char nume[], char prenume[],
		int grupa);
	void afisare();
	int getgrupa();
};
void Persoana::setValoriPersoana(char nume[], char
	prenume[]) {
	strcpy(this->nume, nume);
	strcpy(this->prenume, prenume);
}
void Persoana::afisare() {
	cout << nume << " " << prenume << endl;
}
void Student::setValoriStudent(char nume[], char
	prenume[], int grupa) {
	setValoriPersoana(nume, prenume);
	this->grupa = grupa;
	n++;
}
void Student::afisare() {
	cout << nume << " " << prenume << ", grupa: " <<
		grupa << endl;
}

int Student::getgrupa() {
	return grupa;
}

void sortare(Student student[]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (student[j].getgrupa() > student[j + 1].getgrupa()) {
				Student temp;
				temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}
	}
}

int main() {
	Student student[10];
	student[0].setValoriStudent("Ghita", "Vasile", 1210);
	student[1].setValoriStudent("Gheorghe", "Maria", 1207);
	student[2].setValoriStudent("Alexandru", "Vlad", 1211);
	student[3].setValoriStudent("Radu", "Ionut", 1211);
	student[4].setValoriStudent("Mihnea", "Marian", 1209);
	sortare(student);
	for (int i = 0; i < n; i++) student[i].afisare();
	system("pause");
	return 0;
}
