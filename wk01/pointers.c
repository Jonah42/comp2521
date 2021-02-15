// 2521 Jonah Meggs
// Lets get our hands dirty with pointers

#include <stdio.h>

void addition(int*);
void multiplication(int*);
void address(int*);

int main(void) {
	int* pointer;
	printf("Size of a pointer is %d\n", sizeof(pointer));
	pointer = 42;
	printf("Pointer value is %p\n", pointer);
	printf("In decimal thats %d\n\n", (int)pointer);
	address(pointer);
	addition(pointer);
	multiplication(pointer);

	int x = 528491;
	int* pointerToX = &x;
	return 0;
}

void address(int * pointer) {
	printf("Address is %p\n\n", &pointer);
}

void addition(int* pointer) {
	pointer = pointer + 1;
	printf("After addition:\n");
	printf("Pointer value is %p\n", pointer);
	printf("In decimal thats %d\n\n", (int)pointer);
}

void multiplication(int* pointer) {
	// pointer = pointer * 2;
	// printf("After multiplication:\n");
	// printf("Pointer value is %p\n", pointer);
	// printf("In decimal thats %d\n", (int)pointer);
}