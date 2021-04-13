#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
struct Node {
	int value;
	List next;
};

List append(List l, int x) {
	List new = malloc(sizeof(struct Node));
	new->value = x;
	new->next = l;
	return new;
}

void show(List l) {
	List curr = l;
	while (curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int less(List l1, List l2) {
	return l1->value - l2->value < 0 ? 1 : 0;
}

void swap(List l1, List l2) {
	int tmp = l1->value;
	l1->value = l2->value;
	l2->value = tmp;
}

List selectionSort(List ls) {
	
	return NULL;
}

int main(int argc, char** argv) {
	List l = NULL;
	for (int i = argc - 1; i > 0; i--) l = append(l, atoi(argv[i]));
	show(l);
	selectionSort(l);
	show(l);
}