#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE* fp1 = fopen("in1.txt", "r");
	FILE* fp2 = fopen("in2.txt", "r");
	if (!fp1 ||!fp2) {
		printf("Invalid input file(s).\n");
		return 0;
	}
	int i1, i2;
	int end1 = 1, end2 = 1;
	fscanf(fp1, "%d", &i1);
	fscanf(fp2, "%d", &i2);
	while (end1 != EOF || end2 != EOF) {
		while (end1 != EOF && (i1 <= i2 || end2 == EOF)) {
			printf("%d ", i1);
			end1 = fscanf(fp1, "%d", &i1);
		}
		while (end2 != EOF && (i2 <= i1 || end1 == EOF)) {
			printf("%d ", i2);
			end2 = fscanf(fp2, "%d", &i2);
		}
	}
	printf("\n");

	return 0;
}