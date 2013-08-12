#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "graph.h"
#include "dijkstra.h"

int main()
{
	ptrGraph G;
	Table *T = NULL;

	G = InitializeGraph(7);
	AddVertex(1, 0, G);
	AddVertex(2, 1, G);
	AddVertex(3, 2, G);
	AddVertex(4, 3, G);
	AddVertex(5, 4, G);
	AddVertex(6, 5, G);
	AddVertex(7, 6, G);

	AddEdge(1, 2, 2, G);
	AddEdge(1, 4, 1, G);
	AddEdge(2, 4, 3, G);
	AddEdge(2, 5, 10, G);
	AddEdge(3, 1, 4, G);
	AddEdge(3, 6, 5, G);
	AddEdge(4, 3, 2, G);
	AddEdge(4, 5, 2, G);
	AddEdge(4, 6, 8, G);
	AddEdge(4, 7, 4, G);
	AddEdge(5, 7, 6, G);
	AddEdge(7, 6, 1, G);

	//vertex 1(indexed 0 is the start vertex)
	T = InitTable(1, G, T);
	Dijkstra(T);
	PrintPath(6, T);
	printf("\n");
}