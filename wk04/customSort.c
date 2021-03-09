// Demonstrate the use of a function pointer with qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int customCompare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

int main(int argc, char **argv) {
	// Allocate an array
	char **list = malloc((argc-1)*sizeof(*list));
	// Fill the array from argv
	for (int i = 1; i < argc; i++) list[i-1] = argv[i];
	// Sort!
	qsort(list, argc-1, sizeof(char*), customCompare);
	// Print the result
	for (int i = 0; i < argc-1; i++) printf("%s ", list[i]);
	return 0;
}