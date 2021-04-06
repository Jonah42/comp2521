#include "Graph.h"
#include <stdlib.h>
#include "list.h"



List reachable(Graph g, Vertex src) {
	return NULL;
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