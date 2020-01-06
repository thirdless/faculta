#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class StudentAC
{
	string nume;
	int nota;
public:
	StudentAC();
	StudentAC(string nume1, int nota1);
	void afisare();
	int getNota();
	string getNume();
	void modificareNota(int nouaNota);
	bool StudentAC::operator<(StudentAC s);
};

StudentAC::StudentAC() {
	cin >> nume;
	cin >> nota;
}

StudentAC::StudentAC(string nume1, int nota1) {
	nume = nume1;
	nota = nota1;
}

void StudentAC::afisare() {
	cout << "Nume: " << nume << "\nNota: " << nota << endl;
}

void StudentAC::modificareNota(int nouaNota) {
	nota = nouaNota;
}

bool StudentAC::operator<(StudentAC s) {
	return this->getNota() < s.getNota() ? true : false;
}

int StudentAC::getNota() {
	return nota;
}

string StudentAC::getNume() {
	return nume;
}

void note(vector<StudentAC> v) {
	for (vector<StudentAC>::iterator it = v.begin(); it != v.end(); ++it) {
		it->afisare();
		cout << endl;
	}
}

vector<StudentAC> convert(StudentAC * v, int n) {
	vector<StudentAC> r;
	for (int i = 0; i < n; i++) {
		r.push_back(StudentAC(v[i].getNume(), v[i].getNota()));
	}
	return r;
}

bool compare(StudentAC s1, StudentAC s2) {
	return s1.getNota() > s2.getNota();
}

int main() {
	vector<StudentAC> v;
	v.push_back({"EZ", 2});
	v.push_back({ "LMAO", 10 });
	v.push_back({ "AHA", 7 });
	v.push_back({ "LOL", 5 });
	//note(v);
	sort(v.begin(), v.end(), compare);
	note(v);
	system("pause");
	return 0;
}
