#include "graph.h"
#include "fatal.h"
#include "queue_array.h"

//initialize a Graph
ptrGraph InitializeGraph(int N)
{
	int i;
	ptrGraph G;

	G = malloc(sizeof(Graph));
	if(G == NULL){
		FatalError("Out of space!");
	}
	G->numEdges = 0;
	G->numVertexes = N;
	for(i = 0; i < N; i++){
		G->adjList[i].firstedge = NULL;  
		G->adjList[i].data = 0;
		G->adjList[i].indegree = 0;
	}

	return (G);
}

//destroy a Graph
void Destroy(ptrGraph G)
{

	EdgeNode *tmpEdge;
	EdgeNode *tmpEdge2;
	int i;


	for(i = 0; i < G->numVertexes; i++){
		if(G->adjList[i].firstedge != NULL){
			tmpEdge = G->adjList[i].firstedge;
			while(tmpEdge->next != NULL){
				tmpEdge2 = tmpEdge;
				tmpEdge = tmpEdge->next;
				free(tmpEdge2);
			}
		}
	}

	free(G);
}


//fill Vertex list loc with element x in Graph G
//loc starts with 0
ptrGraph AddVertex(ElemType X, int loc, ptrGraph G)
{
	if(loc < 0 || loc >= G->numVertexes){
		Error("Out of range.");
	}

	G->adjList[loc].data = X;

	return (G);
}

//return the location of element X
int LocateVertex(ElemType X, ptrGraph G)
{
	int i;

	for(i = 0; i < G->numVertexes; i++){
		if(X == G->adjList[i].data){
			return (i);
		}
	}
	return (-1);
}

//insert at the head of the list
ptrGraph AddEdge(ElemType head, ElemType tail, ptrGraph G)
{
	ptrEdgeNode edge;
	int h;

	edge = malloc(sizeof(EdgeNode));
	if(edge == NULL){
		FatalError("Out of space.");
	}
	edge->adjvex = LocateVertex(tail, G);
	(G->adjList[edge->adjvex].indegree)++;

	h = LocateVertex(head, G);
	edge->next = G->adjList[h].firstedge;  //insert at the head
	G->adjList[h].firstedge = edge;
	(G->numEdges)++;

	return (G);
}

//get all nodes' indegree and store in another array
void GetIndegree(ptrGraph G)
{
	int i = 0;

	for(i = 0; i < G->numVertexes; i++){
		inDegree[i].degree = G->adjList[i].indegree;
		inDegree[i].flag = 0;  //unsorted
	}
}

//find the index of Vertex with indegree of 0
int FindNewVertexOfIndegreeZero(ptrGraph G)
{
	int i;

	for(i = 0; i < G->numVertexes; i++){
		if(inDegree[i].flag == 0){
			if(inDegree[i].degree == 0){
				inDegree[i].flag = 1;  //sorted
				return i;
			}
		}
	}
	return -1;
}




void TopSort(ptrGraph G)
{
	int Counter = 0;
	QueueRecord *Q;
	int v;
	int TopNum[MAXVEX];
	EdgeNode *tmpEdge;
	int i;
	Index tmp;

	Q = initQueue(G->numVertexes);

	//for each vertex, enqueue v if indegree == 0
	for(i = 0; i < G->numVertexes; i++){  
		if(inDegree[i].degree == 0){
			/*enQueue(G->adjList[i].data, Q);*/
			enQueue(i, Q);  //enQueue the index
		}
	}

	while(!isEmpty(*Q)){
		tmp = deQueue(Q);
		TopNum[Counter++] = tmp;
	
		//for each W adjacent to V, indegree--
		tmpEdge = G->adjList[tmp].firstedge;
		while(tmpEdge != NULL){
			if(--inDegree[tmpEdge->adjvex].degree == 0){
				enQueue(tmpEdge->adjvex, Q);
			}
			tmpEdge = tmpEdge->next;
		}
	}


	for(i = 0; i < G->numVertexes; i++){
		printf("%d   ", G->adjList[TopNum[i]].data);
	}
}


