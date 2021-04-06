#include "Graph.h"
#include <stdlib.h>

bool isEulerPath(Graph g, Edge e[], int nE) {
	// Passes through each edge once
	// So, assuming e is a valid path, that means that for e to be a Euler path:
		// e must have the same number of edges as our graph and
		// no edge should be repeated
	// 1. Check that e has the same number of edges as g
	int numEdges = 0;
	for (int e1 = 0; e1 < GraphNumVertices(g); e1++)
		for (int e2 = e1 + 1; e2 < GraphNumVertices(g); e2++)
			if (GraphIsAdjacent(g, e1, e2)) numEdges++;
	if (numEdges != nE) return false;
	// 2. Check that no edge is repeated
	int *edges = calloc(nE*nE, sizeof(int));
	for (int i = 0; i < nE; i++)
		edges[e[i].v*nE+e[i].w]++;
	for (int i = 0; i < nE*nE; i++)
		if (edges[i] > 1) return false;
	return true;
}

int main(void) {
	Graph g = GraphRead();
	int nE;
	Edge* e = EdgeRead(&nE);
	printf("Is Euler path? %s\n", isEulerPath(g, e, nE) ? "True" : "False");
	GraphFree(g);
	free(e);
	return 0;
}