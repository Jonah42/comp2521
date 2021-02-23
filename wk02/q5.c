//Written by Jonah Meggs for COMP2521 21T1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int my_pow(int x, unsigned int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = res * x;
	}
	return res;
}

int main(int argc, char* argv[]) {
	assert(argc == 3);
	int result = my_pow(atoi(argv[1]), atoi(argv[2]));
	printf("Result: %d\n", result);
	return 0;
}