#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "graph.h"




int main()
{
	ptrGraph G;
	//Indegree inDegree[MAXVEX];
	int tmp;

	G = InitializeGraph(7);
	AddVertex(1, 0, G);
	AddVertex(2, 1, G);
	AddVertex(3, 2, G);
	AddVertex(4, 3, G);
	AddVertex(5, 4, G);
	AddVertex(6, 5, G);
	AddVertex(7, 6, G);

	AddEdge(1, 2, G);
	AddEdge(1, 3, G);
	AddEdge(1, 4, G);

	AddEdge(2, 4, G);
	AddEdge(2, 5, G);
	AddEdge(3, 6, G);

	AddEdge(4, 7, G);
	AddEdge(4, 3, G);
	AddEdge(4, 6, G);

	AddEdge(5, 4, G);
	AddEdge(5, 7, G);
	AddEdge(7, 6, G);

	GetIndegree(G);
	//tmp = FindNewVertexOfIndegreeZero(inDegree, G->numVertexes);
	TopSort(G);
}