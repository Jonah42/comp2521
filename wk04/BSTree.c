#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define NOT_HEIGHT_BALANCED -99

typedef struct node BSTNode;
typedef Tree BSTree;

int isHeightBalanced(BSTree t) {
	if (t == NULL) return 0;
	int leftHeight = isHeightBalanced(t->left);
	int rightHeight = isHeightBalanced(t->right);
	return leftHeight == NOT_HEIGHT_BALANCED || rightHeight == NOT_HEIGHT_BALANCED || abs(leftHeight - rightHeight) > 1 ? NOT_HEIGHT_BALANCED : 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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
	int ret = isHeightBalanced(t);
	if (ret == NOT_HEIGHT_BALANCED) printf("Tree not height balanced!!\n");
	else printf("Height: %d\n", isHeightBalanced(t));
	return 0;
}