#ifndef _GRUPA_
#define _GRUPA_

#include "student.h"

struct Grupa{
	Student* tab;
	int nr;
	int id;
};

void InitGrupa(struct Grupa &grupa);
void AfisGrupa(struct Grupa grupa);
void StergeGrupa(struct Grupa &grupa);

#endif