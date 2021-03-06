#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct _Student {
	private:
		char * nume;
		int nota;
	public:
		int getNota(void);
		void setNota(int v);
		char * getNume(void);
		void setNume(char unNume[]);
		void elibMem(void);
		void citire(void);
		void afisare(void);
}Student;

typedef int(*PFnComparare)(Student a, Student b);

typedef struct _Grupa {
	int nrStud;
	Student * tabStudenti;
	char * numeGrupa;
	void citire(void);
	void afisare(void);
	PFnComparare comparator;
	void bSort(void);
	void elibMem(void);
}Grupa;

typedef struct _Catalog {
	int nrGrupe;
	Grupa * tabGrupe;
	void setComparator(PFnComparare comparator);
	void citire(void);
	void afisare(void);
	void sortare(void);
	void elibMem(void);
} Catalog;

int comparNumeAlfabetic(Student a, Student b);
int comparNoteDescrescator(Student a, Student b);
int comparNumeDupaLungimeCrescator(Student a, Student b);

void swap2(Student &a, Student &b);