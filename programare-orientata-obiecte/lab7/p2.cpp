#include<iostream>
#include<string.h>
using namespace std;

class String {
	char var[100];

	public:
		String();
		String(char*);
		String(String &);
		String operator + (String);
		bool operator == (String);
		String& operator=(const String &src);
		int cauta(String subsir);
		void afisare();
		int compara(String sir2);
		~String();
};

String::String() {
	strcpy(var, "");
}

String::String(char * c2) {
	strcpy(var, c2);
}

String::String(String &d) {
	strcpy(var, d.var);
}

String::~String() {
	strcpy(var, "");
}

String String::operator+(String c2) {
	String temp;
	strcat(temp.var, this->var);
	strcat(temp.var, c2.var);
	return temp;
}


bool String::operator==(String c2) {
	if (strcmp(this->var, c2.var) == 0) return true;
	return false;
}

String& String::operator=(const String &src) {
	strcpy(this->var, src.var);
	return *this;
}

int String::compara(String sir2) {
	return strcmp(this->var, sir2.var);
}

void String::afisare() {
	cout << var << endl;
}

int String::cauta(String subsir) {
	int length = strlen(var);
	char temp[100];
	for (int i = 1; i <= length; i++) {
		for (int j = 0; i + j <= length; j++) {
			strncpy(temp, var[j], i);
			if (strcmp(temp, subsir.var)) return j;
		}
	}
	return -1;
}

int main() {
	String a("CEVAXDCEVA");
	String b("XD");
	String c;
	c = a + b;
	c.afisare();
	c = b;
	c.afisare();
	cout << a.compara(b) << " " << (a == b) << endl;
	cout << a.cauta(b) << endl;
	system("pause");
}
