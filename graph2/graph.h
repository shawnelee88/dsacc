/*different from project graph*/
/*interfaces are more like description from book*/
/*define a global array Indegree inDegree[MAXVEX]*/
/*instead of passing it as parameters as project graph do*/

#ifndef GUARD_GRAPH_H
#define GUARD_GRAPH_H

#define MAXVEX 50
typedef int ElemType;
typedef int EdgeType;
typedef struct _EdgeNode{
	int adjvex;    //index of node in adjList
	EdgeType weight;  //for graph with weighted edges
	struct _EdgeNode *next;  //point to next node has the same start node
}EdgeNode;
typedef EdgeNode *ptrEdgeNode;

typedef struct _Vertex{
	ElemType data;  //element in the node
	int indegree;  //in degree of node
	EdgeNode *firstedge;  //point to adjacent nodes list
}Vertex, AdjList[MAXVEX];
typedef Vertex *ptrVertex;

typedef struct _Graph{
	AdjList adjList;
	int numVertexes;
	int numEdges;
}Graph;
typedef Graph *ptrGraph;

typedef struct _Indegree{
	int degree;
	int flag;  //0-unsorted; 1-sorted
}Indegree;
Indegree inDegree[MAXVEX];

ptrGraph InitializeGraph(int N);
ptrGraph AddVertex(ElemType X, int loc, ptrGraph G);
int LocateVertex(ElemType X, ptrGraph G);
ptrGraph AddEdge(ElemType head, ElemType tail, ptrGraph G);
void GetIndegree(ptrGraph G);
int FindNewVertexOfIndegreeZero(ptrGraph G);
void TopSort(ptrGraph G);

#endif