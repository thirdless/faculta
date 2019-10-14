#ifndef __LOL__
#define __LOL__

struct student_C {
	int nrMatricol;
	char nume[100];
	char gen;
	float nota;
	void(*read)(student_C * st);
	void(*write)(student_C * st);
};

void ReadData(student_C * st);
void WriteData(student_C * st);

#endif