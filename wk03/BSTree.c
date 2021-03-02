#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node BSTNode;
typedef Tree BSTree;

int BSTreeNumNodes(BSTree t) {
	return 0;
}

int BSTreeCountOdds(BSTree t) {
	return 0;
}

int BSTreeHeight(BSTree t) {
	return 0;
}

int BSTreeCountInternal(BSTree t) {
	return 0;
}

int BSTreeNodeDepth(BSTree t, int key) {
	return 0;
}

int BSTreeCountGreater(BSTree t, int key) {
	return 0;
}

BSTree createNode(int value) {
	BSTree new = malloc(sizeof(*new));
	new->left = new->right = NULL;
	new->value = value;
	return new;
}

BSTree insert(BSTree t, int value) {
	if (t == NULL) return createNode(value);
	if (value < t->value) t->left = insert(t->left, value);
	else t->right = insert(t->right, value);
	return t;
}

int main(int argc, char **argv) {
	BSTree t = NULL;
	for (int i = 1; i < argc; i++) t = insert(t, atoi(argv[i]));
	printTree(t);
	printf("NumNodes: %d\n", BSTreeNumNodes(t));
	printf("CountOdds: %d\n", BSTreeCountOdds(t));
	printf("Height: %d\n", BSTreeHeight(t));
	printf("CountInternal: %d\n", BSTreeCountInternal(t));
	printf("NodeDepth: %d\n", BSTreeNodeDepth(t, 6));
	printf("CountGreater: %d\n", BSTreeCountGreater(t, 5));
	return 0;
}