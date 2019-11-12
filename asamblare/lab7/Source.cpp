
#include <stdio.h>
extern "C" unsigned long int AsmFunction(unsigned long int * a, unsigned long int n);

int main()
{
	unsigned long int i[7] = {1,2,3,4,5,6,7};
	unsigned long b = AsmFunction(i, 7);
	printf("i = %u\n", b);
	return 0;
}
