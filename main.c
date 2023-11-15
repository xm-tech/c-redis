#include "zmalloc.h"
#include <stdio.h>

typedef struct person {
	int age;
} person;

int main(){
	printf("hello %c\n", 'c');
	printf("hello %s\n", "c");

	person *p =  (person*)zmalloc(sizeof(*p));
	p->age = 13;

	printf("p.age=%d\n", p->age);
}

