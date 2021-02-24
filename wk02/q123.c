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
	//base case
	if (l == NULL) return 0;
	//general case
	return 1 + listLength(l->next);
}

int listCountOdds(List l) {
	//base case
	if (l == NULL) return 0;
	return (l->data % 2 != 0 ? 1 : 0) + listCountOdds(l->next);
}

bool listIsSorted(List l) {
	if (l == NULL || l->next == NULL) return true;
	return l->data <= l->next->data && listIsSorted(l->next);
}

int main(int argc, char* argv[]) {
	List l = NULL;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	int length = listLength(l);
	int odds = listCountOdds(l);
	bool isSorted = listIsSorted(l);
	printf("Hello\n");
	printf("Length: %d\nOdds: %d\nSorted: %s\n", length, odds, isSorted?"Yes":"No");
	return 0;
}