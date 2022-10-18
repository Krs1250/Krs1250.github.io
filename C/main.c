#include <stdio.h>
#include "max.h"

typedef struct{
	char name[50];
	int age;
	double point;
} student;

int main(void)
{
	student li = {"Li", 33, 12.5};
	printf("%s\n %d\n %f\n", li.name, li.age, li.point);
	
	return 0;
}