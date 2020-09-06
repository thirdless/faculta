#pragma once

class ElementMeniu {
private:
	char* nume;
	ElementMeniu* parinte;
protected:
	ElementMeniu(const char* nume);
	virtual ~ElementMeniu();
	void afisareIncompletaTitlu();
	void afisareTitlu();
public:
	char* getNume();
	virtual void executa() = 0;
	friend class Meniu;
};

class Operatie : public ElementMeniu {
protected:
	Operatie(const char* nume);
	virtual void execOperatie() = 0;
public:
	void executa();
};

class Meniu : public ElementMeniu {
private:
	static const int nrMaxElemente = 9;
	int nrElemente;
	ElementMeniu** elemente;
	void afisare();
	int citireComanda();
public:
	Meniu(const char* nume);
	//va dealoca fii sai, eventual recursiv.
	~Meniu();
	void adaugaElement(ElementMeniu* element);
	void executa();
};

class OperatieAdunare : public Operatie {
public:
	OperatieAdunare(const char* nume);
	void execOperatie();
};

class OperatieScadere : public Operatie {
public:
	class OperatieScadere(const char* nume);
	void execOperatie();
};

class Lista {
private:
	int* elem;
	int n, dim;
public:
	Lista(int dim);
	~Lista();
	void operator+=(int num);
	void operator+=(Lista& lst);
	int operator[](int num);
	void sterge(int index);
	//afiseaza numerele si indecsii lor
	void afisare();
	int getDim();
};

class OpAdaugaInLista : public Operatie {
private:
	Lista* lista;
public:
	OpAdaugaInLista(const char* nume, Lista* lista);
	void execOperatie();
};

class OpStergereLista : public Operatie {
private:
	Lista* lista;
public:
	OpStergereLista(const char* nume, Lista* lista);
	void execOperatie();
};

class OpAfisareLista : public Operatie {
private:
	Lista* lista;
public:
	OpAfisareLista(const char* nume, Lista* lista);
	void execOperatie();
};

class OpConcatLista : public Operatie {
private:
	Lista* lista;
	Lista* lista2;
public:
	OpConcatLista(const char* nume, Lista* lista, Lista* lista2);
	void execOperatie();
};
