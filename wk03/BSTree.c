#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node BSTNode;
typedef Tree BSTree;

int BSTreeNumNodes(BSTree t) {
	if (t == NULL) return 0;
	return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}

int BSTreeCountOdds(BSTree t) {
	if (t == NULL) return 0;
	return (t->value % 2 != 0 ? 1 : 0) + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
}

int BSTreeHeight(BSTree t) {
	if (t == NULL) return 0;
	int leftHeight = BSTreeHeight(t->left);
	int rightHeight = BSTreeHeight(t->right);
	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int BSTreeCountInternal(BSTree t) {
	if (t == NULL) return 0;
	if (t->left == NULL && t->right == NULL) return 0;
	return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
}

int BSTreeNodeDepth(BSTree t, int key) {
	if (t == NULL) return -1;
	if (key < t->value) {
		int depth = BSTreeNodeDepth(t->left, key);
		return depth == -1 ? -1 : 1 + depth;
	} else if (key > t->value) {
		int depth = BSTreeNodeDepth(t->right, key);
		return depth == -1 ? -1 : 1 + depth;
	}
	return 0;
}

int BSTreeCountGreater(BSTree t, int key) {
	if (t == NULL) return 0;
	if (t->value <= key) return BSTreeCountGreater(t->right, key);
	return 1 + BSTreeCountGreater(t->left, key) + BSTreeCountGreater(t->right, key);
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