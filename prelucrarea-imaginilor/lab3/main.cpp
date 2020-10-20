#include <QApplication>
#include "ImageGrid.h"
#include "operatii.h"

/* Shortcuts:

Scroll wheel - zoom in/out

Left button drag - deplasare in imagine cand aceasta este mai mare decat fereastra

Ctrl+A - activeaza / dezactiveaza ajustarea automata a dimensiunii imaginii 
		 pe care se afla cursorul mouse-ului

Shift+A - activeaza / dezactiveaza ajustarea automata a dimensiunii 
		  tuturor imaginilor

Ctrl+R - reseteaza imaginea curenta la dimensiunile sale initiale

Shift+R - reseteaza toate imaginile la dimensiunile lor initiale

*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/* generam o fereastra care va contine una sau mai multe imagini
	   plasate sub forma unei matrici 2D */
	ImageGrid *grid = new ImageGrid("Prelucrarea imaginilor");
	ImageGrid *grid1 = new ImageGrid("Prelucrarea imaginilor 1");

	QString imageDir = "Images/";
	QString imageFile(imageDir + "lena512.bmp");
	QString imageFile1(imageDir + "photo256.jpg");
	QString imageFile2(imageDir + "Fig5.03.jpg");

	/*adaugam prima imagine, cea initiala, citita din fisier,
	in pozitia stanga-sus (linia 0, coloana 0)*/

	/* extragem imformatiile necesare din imagine:
	dimensiunile ei si un sir de octeti care contine valorile
	intensitatilor pentru fiecare pixel */
	int w, h;
	int w1, h1;
	int w2, h2;
	unsigned char* img = Tools::readImageGray8(imageFile, w, h);
	unsigned char* img1 = Tools::readImageGray8(imageFile1, w1, h1);
	unsigned char* img2 = Tools::readImageGray8(imageFile2, w2, h2);

	// exemplu de operatie: negativarea unei imagini 

	/*parcurgem imaginea pixel cu pixel si determinam valoarea complementara
	pentru fiecare intensitate

	se recomanda ca acest gen de operatie sa se implementeze intr-o functie
	separata sau intr-o alta clasa
	*/

	//unsigned char* negated = negateImage(img, w, h);

	unsigned char* brightness = brightImage(img, w, h, 100);
	unsigned char* compressContrast = compressContrastImage(img, w, h, 35);


	/* afisam imaginea astfel obtinuta la dreapta celei initiale;
	parametrii cu valorile 0, 1 semnifica prima linie, respectiv
	a doua coloana a imageGrid-ului
	*/
	//grid->addImage(negated, w, h, 0, 1, "negativ");

	#define SIZE 256

	grid->addImage(imageFile, 0, 0);
	grid->addImage(imageFile1, 0, 2);
	grid->addImage(imageFile2, 1, 0);

	int* pointerVal, *pointerVal1, *pointerVal2;

	pointerVal = getHistogram(img, w, h, SIZE);
	pointerVal1 = getHistogram(img1, w1, h1, SIZE);
	pointerVal2 = getHistogram(img2, w2, h2, SIZE);		

	grid->addHistogram(pointerVal, SIZE, 0, 1);
	grid->addHistogram(pointerVal1, SIZE, 0, 3);
	grid->addHistogram(pointerVal2, SIZE, 1, 1);

	grid->addImage(img, w, h, 2, 0);
	grid->addHistogram(getHistogram(img, w, h, SIZE), SIZE, 2, 1);
	grid->addImage(brightness, w, h, 2, 2);
	grid->addHistogram(getHistogram(brightness, w, h, SIZE), SIZE, 2, 3);

	grid->addImage(img, w, h, 3, 0);
	grid->addHistogram(getHistogram(img, w, h, SIZE), SIZE, 3, 1);
	grid->addImage(compressContrast, w, h, 3, 2);
	grid->addHistogram(getHistogram(compressContrast, w, h, SIZE), SIZE, 3, 3);

	grid1->addImage(img1, w1, h1, 0, 0);
	grid1->addHistogram(getHistogram(img1, w1, h1, SIZE), SIZE, 0, 1);

	unsigned char * equalized = equalize(img1, w1, h1);

	grid1->addImage(equalized, w1, h1, 1, 0);
	grid1->addHistogram(getHistogram(equalized, w1, h1, SIZE), SIZE, 1, 1);

	grid->show();
	grid1->show();
	
	return a.exec();
}

