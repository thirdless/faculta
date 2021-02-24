#pragma once
#include <QWidget>
#include <QPainter>
#include <cmath>

#define M_PI 3.141592

class MyWidget1 : public QWidget
{
	int xc, yc; // centrul ferestrei
	float x[4], y[4]; // coordonatele varfurilor unui patrat
	int N; //nr de patrate
		
public:
	MyWidget1(QWidget *parent = nullptr) : QWidget(parent)
	{
		xc = width() / 2;
		yc = height() / 2;
		N = 10;
		init_obiect(60, 50);
	}

	void desen(QPainter &painter, QPen &pen)
	{
		//deseneaza un patrat cu varfurile (x[0] y[0]), (x[1] y[1]), etc.
		painter.setPen(pen);
		for (int i = 0; i < 3; i++)
			painter.drawLine(x[i], y[i], x[i + 1], y[i + 1]);
		painter.drawLine(x[3], y[3], x[0], y[0]);
	}

	void init_obiect(int raza, int latura)
	{
		//functie ce calculeaza coordonatele varfurilor in pozitia initiala
		
		//...
		x[0] = x[3] = xc + raza - latura / 2;
		x[1] = x[2] = xc + raza + latura / 2;

		y[0] = y[1] = yc - latura / 2;
		y[2] = y[3] = yc + latura / 2;
	}

	void paintEvent(QPaintEvent *e)
	{
		QPainter painter(this);
		QPen pen(Qt::red);

		float du = 2 * M_PI / N; //unghiul dintre doua patrate succesive
		float c = cos(du);
		float s = sin(du);
		int x_old[4], y_old[4];

		for (int i = 0; i < N; i++)
		{
			/*
			- se deseneaza patratul curent
			- se calculeaza noi valori pentru x[], y[]
			prin aplicarea unor transformari de translatie / rotatie, dupa caz
			*/
			desen(painter, pen);

			for (int i = 0; i < 4; i++) {
				x_old[i] = x[i];
				y_old[i] = y[i];

				x[i] = x_old[i] * c - y_old[i] * s + xc - xc * c + yc * s;
				y[i] = x_old[i] * s + y_old[i] * c + yc - xc * s - yc * c;
			}
		}
	}
};

class MyWidget2 : public QWidget
{
	int xc, yc; // centrul ferestrei
	float x[4], y[4]; // coordonatele varfurilor unui patrat
	int xcp, ycp; // coordonatele centrului patratului
	int raza, latura;
	int N; //nr de patrate
public:
	MyWidget2(QWidget *parent = nullptr) : QWidget(parent)
	{
		xc = width() / 2;
		yc = height() / 2;
		N = 10;
		init_obiect(100, 40);
	}
	void desen(QPainter &painter, QPen &pen)
	{
		//deseneaza un patrat cu varfurile (x[0] y[0]), (x[1] y[1]), etc.
		painter.setPen(pen);
		for (int i = 0; i < 3; i++)
			painter.drawLine(x[i], y[i], x[i + 1], y[i + 1]);
		painter.drawLine(x[3], y[3], x[0], y[0]);
	}
	void init_obiect(int _raza, int _latura)
	{
		//functie ce calculeaza coordonatele varfurilor in pozitia initiala
		
	}
	void paintEvent(QPaintEvent *e)
	{
		QPainter painter(this);
		QPen pen(Qt::blue);
		float du = 2 * M_PI / N; //unghiul dintre doua patrate succesive
		float c = cos(du);
		float s = sin(du);
		int L2 = latura / 2;
		for (int i = 0; i < N; i++)
		{
			// se deseneaza patratul curent
			// se calculeaza noua pozitie a centrului patratului
			// se determina coordonatele varfurilor noului patrat functie de pozitia noului centru
		}
	}
};
