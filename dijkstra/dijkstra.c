#include "fatal.h"
#include "dijkstra.h"
#include "queue_array.h"

//read in Graph and store vertexes in a table T
void ReadGraph(ptrGraph G, Table *T)
{
	int i;
	ptrEdgeNode tmpEdge;
	Position P;
	Position E;

	

	for(i = 0; i < G->numVertexes; i++){
		//store vertex
		E = malloc(sizeof(Node));
		if(E == NULL){
			FatalError("Out of space.");
		}
		P = T->table[i].Header;
		E->data = G->adjList[i].data;
		E->weight = 0;
		E->next = NULL;
		Insert(T->table[i].Header, E, P);
		P = Advance(P);

		//store edges with weight and index of vertex 
		tmpEdge = G->adjList[i].firstedge;
		while(tmpEdge != NULL){
			E = malloc(sizeof(Node));
			if(E == NULL){
				FatalError("Out of space.");
			}

			E->data = tmpEdge->adjvex;
			E->weight = tmpEdge->weight;
			E->next = NULL;
			Insert(T->table[i].Header, E, P);
			P = Advance(P);
			tmpEdge = tmpEdge->next;
		}
		T->capacity++;
	}
}


//initialize a table with vertex x be the start vertex
Table *InitTable(ElemType x, ptrGraph G, Table *T)
{
	int i;
	Index Start;

	Start = LocateVertex(x, G);
	T = malloc(sizeof(Table));
	if(T == NULL){
		FatalError("Out of space.");
	}
	for(i = 0; i < NumVertex; i++){
		T->table[i].Header = MakeEmpty(NULL);
	}

	T->capacity = 0;
	ReadGraph(G, T);   //Read graph somehow
	for(i = 0; i < G->numVertexes; i++){
		T->table[i].Known = 0;
		T->table[i].Dist = Infinity;
		T->table[i].Path = NotAVertex;
	}
	T->table[Start].Dist = 0;
	T->table[Start].Path = -1;
	return T;
}


//return index of smallest distance in the Table
Index FindSmallestDistance(Table *T)
{
	int i;
	ElemType min = Infinity;
	int flag = 0;
	Index index;

	for(i = 0; i < T->capacity; i++){
		if(T->table[i].Known == 0){
			if(min > T->table[i].Dist){
				min = T->table[i].Dist;
				index = i;
				flag = 1;
			}
		}	
	}

	if(flag == 0){  //not found
		return NotAVertex;
	}else{  //found
		return index;
	}
	
}



void Dijkstra(Table *T)
{
	Index v, w;
	Position P;

	for(;;){
		v = FindSmallestDistance(T);
		if(v == NotAVertex){
			break;
		}

		T->table[v].Known = 1;
		//for each W adjacent to V
		P = T->table[v].Header->next->next;
		while(P != NULL){
			w = P->data;  //index of adjacent node
			if(!T->table[w].Known){
				if(T->table[v].Dist + P->weight < T->table[w].Dist){
					//Decrease(T[W].Dist to T[V].Dist + Cvw);
					T->table[w].Dist = T->table[v].Dist + P->weight;
					T->table[w].Path = v;
				}
			}
			P = P->next;
		}
	}
}

int LocateVertexInTable(ElemType X, Table *T)
{
	int i;

	for(i = 0; i < T->capacity; i++){
		if(X == T->table[i].Header->next->data){
			return (i);
		}
	}
	return (-1);
}
//Print shortest path to vertex x(indexed End) after Dijkstra has run
//Assume that the path exists
//If vertex x is the start(defined in InitTable)itself, just print it
void PrintPath(ElemType x, Table *T)
{
	Index path = 0;

	//because order of vertexes in Graph and Table are corresponding,
	//so we can use LocateVertex here
	//only the dist of start vertex(defined in InitTable) is 0
	if(T->table[LocateVertexInTable(x, T)].Dist == 0){
		printf("%d", x);
	}else{
		path = T->table[LocateVertexInTable(x, T)].Path;
		if(path != NotAVertex){
			PrintPath(T->table[path].Header->next->data, T);
			printf(" to ");
		}
		printf("%d", x);
	}	
}
#if 0
//fig.9_58
void Kruskal(Graph G)
{
	int EdgesAccepted;
	DisjSet S;
	PriorityQueue H;
	Vertex U, V;
	SetType Uset, Vset;
	Edge E;

	Initialize(S);
	ReadGraphIntoHeapArray(G, H);
	BuildHeap(H);

	EdgesAccepted = 0;
	while(EdgesAccepted < NumVertex - 1){  //|V| - 1
		E = DeleteMin(H);  //E = (U, V);
		Uset = Find(U, S);
		Vset = Find(V, S);
		if(Uset != Vset){
			//accept the edge
			EdgesAccepted++;
			SetUnion(S, Uset, Vset);
		}
	}
}


//fig.9_33
void WeightedNegative(Table T)  //assume T is initialized 
{
	Queue Q;
	Vertex v, w;

	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	enQueue(S, Q);

	while(!isEmpty(Q)){
		v = deQueue(Q);
		for each w adjacent to v{
			if(T[v].Dist + Cvw < T[W].Dist){
				T[w].Dist = T[v].Dist + Cvw;
				T[w].Path = v;
				if(w is not already in Q){
					enQueue(w, Q);
				}
			}
		}
	}
	disposeQueue(Q);
}


//fig.9_16
void Unweighted(Table T)  //Assume T is initialized, fig.9_16
{
	int CurrDist;
	Vertex V, W;

	for(CurrDist = 0; CurrDist < NumVertex; CurrDist++){
		for each Vertex V{
			if(!T[V].Known && T[V].Dist == CurrDist){
				T[V].Known = True;
				for each W adjacent to V{
					if(T[W].Dist == Infinity){
						T[W].Dist = CurrDist + 1;
						T[W].Path = V;
					}
				}
			}
		}
	}
}

//fig.9_18
void Unweighted2(Table T)  //Assume T is initialized. Fig.9_18
{
	Queue Q;
	Vertex V, W;

	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	enQueue(S, Q);  //enqueue the start vertex S, determined elsewhere
	while(!isEmpty(Q)){
		V = deQueue(Q);
		T[V].Known = True;   //not really needed anymore

		for each W adjacent V{
			if(T[W].Dist == Infinity){
				T[W].Dist = T[V].Dist + 1;
				T[W].Path = V;
				enQueue(W, Q);
			}
		}
	}

	disposeQueue(Q);
}

#endif