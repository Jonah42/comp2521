#include <stdio.h>
#include <stdlib.h>

int hash(char *key, int N) {
	int h = 0;
	char *c;
	for (c = key; *c != '\0'; c++)
		h = h + *c;
	return h % N;
}

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("Usage: q5 <key> <N>\n");
		return 0;
	}
	printf("Hash of %s: %d\n", argv[1], hash(argv[1], atoi(argv[2])));
	return 0;
}