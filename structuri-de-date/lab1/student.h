#ifndef _STUDENT_
#define _STUDENT_

struct Student{
	char* nume;
	int nota;
};

void InitStudent(struct Student &student);
void AfisStudent(struct Student student);
void StergeStudent(struct Student &student);

#endif