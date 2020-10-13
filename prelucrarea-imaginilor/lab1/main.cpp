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

	QString imageDir = "Images/";
	QString imageFile(imageDir + "lena512.bmp");
	QString imageFile1(imageDir + "Fig5.03.jpg");

	/*adaugam prima imagine, cea initiala, citita din fisier,
	in pozitia stanga-sus (linia 0, coloana 0)*/
	grid->addImage(imageFile, 0, 0);

	/* extragem imformatiile necesare din imagine:
	dimensiunile ei si un sir de octeti care contine valorile
	intensitatilor pentru fiecare pixel */
	int w, h;
	int w1, h1;
	unsigned char* img = Tools::readImageGray8(imageFile, w, h);
	unsigned char* img1 = Tools::readImageGray8(imageFile1, w1, h1);

	// exemplu de operatie: negativarea unei imagini 

	/*parcurgem imaginea pixel cu pixel si determinam valoarea complementara
	pentru fiecare intensitate

	se recomanda ca acest gen de operatie sa se implementeze intr-o functie
	separata sau intr-o alta clasa
	*/

	unsigned char* negated = negateImage(img, w, h);

	unsigned char* binary = binaryImage(img, w, h, 105);

	unsigned char* brightness = brightImage(img, w, h, 100);

	unsigned char* contrast = contrastImage(img, w, h, 0, 100, 50);

	unsigned char* gamma = gammaImage(img, w, h, 2.5f);

	unsigned char* bitSlice = bitSliceImage(img1, w1, h1, 7);

	unsigned char* compressContrast = compressContrastImage(img, w, h, 35);

	/* afisam imaginea astfel obtinuta la dreapta celei initiale;
	parametrii cu valorile 0, 1 semnifica prima linie, respectiv
	a doua coloana a imageGrid-ului
	*/
	grid->addImage(negated, w, h, 0, 1, "negativ");

	grid->addImage(binary, w, h, 1, 0, "binary");

	grid->addImage(brightness, w, h, 1, 1, "brightness");

	grid->addImage(contrast, w, h, 2, 0, "contrast");

	grid->addImage(gamma, w, h, 2, 1, "gammaContrast");

	grid->addImage(bitSlice, w1, h1, 3, 0, "bitSlice");

	grid->addImage(compressContrast, w, h, 3, 1, "compressContrast");

	grid->show();
	
	return a.exec();
}

