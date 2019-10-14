#include<iostream>
using namespace std;

typedef struct Catalog {
	int nrStudenti;
	char ** nume;
	void sortLung(void);
	void sortAlfa(void);
	void citire(void);
};

void Catalog::sortLung(void) {
	int suntPerm = 1;
	while (suntPerm) {
		suntPerm = 0;
		for (int i = 0; i<nrStudenti - 1; i++) {
			if (strlen(nume[i]) > strlen(nume[i + 1])) {
				char *aux = nume[i];
				nume[i] = nume[i + 1];
				nume[i + 1] = aux;
				suntPerm = 1;
			}
		}
	}

}

void Catalog::sortAlfa(void) {
	int suntPerm = 1;
	while (suntPerm) {
		suntPerm = 0;
		for (int i = 0; i < nrStudenti - 1; i++) {
			if (strcmp(nume[i],
				nume[i + 1]) > 0) {
				char *aux = nume[i];
				nume[i] = nume[i + 1];
				nume[i + 1] = aux;
				suntPerm = 1;
			}
		}
	}

}

void Catalog::citire(void) {
	char buffer[100];
	char **nume = (char**)calloc(nrStudenti, sizeof(char*));
	cin.ignore(100, '\n');
	for (int i = 0; i<nrStudenti; i++) {
		int len;
		cin.getline(buffer, 100);
		len = strlen(buffer);
		nume[i] = (char*)calloc(len + 1, sizeof(char));
		strcpy(nume[i], buffer);
	}
}

int main(void) {
	Catalog catalogcpp;

	cout << "Numar studenti: ";
	cin >> catalogcpp.nrStudenti;
	cout << catalogcpp.nrStudenti;

	catalogcpp.citire();
	catalogcpp.sortAlfa();
	catalogcpp.sortLung();



	for (int i = 0; i<catalogcpp.nrStudenti; i++) {
		free(catalogcpp.nume[i]);
	}
	free(catalogcpp.nume);


	system("pause");
	return 0;
}
