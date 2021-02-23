//Written by Jonah Meggs for COMP2521 21T1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef Node *List;

List append(List l, int x) {
	Node* new = malloc(sizeof(Node));
	new->data = x;
	new->next = l;
	return new;
}

void show(List l) {
	Node* curr = l;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int listLength(List l) {
	return 0;
}

int listCountOdds(List l) {
	return 0;
}

bool listIsSorted(List l) {
	return false;
}

int main(int argc, char* argv[]) {
	List l;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	int length = listLength(l);
	int odds = listCountOdds(l);
	bool isSorted = listIsSorted(l);
	printf("Length: %d\nOdds: %d\nSorted: %s\n", length, odds, isSorted?"Yes":"No");
	return 0;
}