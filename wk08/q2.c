#include "Graph.h"
#include <stdlib.h>
#include "list.h"

void dfs(Graph g, Vertex src, int *vist) {
	vist[src] = 1;
	int n = GraphNumVertices(g);
	for (int i = 0; i < n; i++) {
		if (vist[i] == 0 && GraphIsAdjacent(g, src, i)) dfs(g, i, vist);
	}
}

List reachable(Graph g, Vertex src) {
	List l = newList();
	int *vist = calloc(GraphNumVertices(g), sizeof(int));
	dfs(g, src, vist);
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (vist[i]) listAppend(l, i);
	}
	return l;
}

int main(void) {
	Graph g = GraphRead();
	printf("Reachable nodes: \n");
	List l = reachable(g, 9);
	printListSet(l);
	GraphFree(g);
	freeList(l);
	return 0;
}