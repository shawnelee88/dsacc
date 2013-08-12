
#ifndef GUARD_DIJKSTRA_H
#define GUARD_DIJKSTRA_H

#include "list.h"
#include "graph.h"

#define NumVertex 30
#define Infinity 65535
#define NotAVertex -1


typedef int DistType;
typedef int Index;
typedef struct _TableEntry{
	List Header;  //adjacent list
	int Known;
	DistType Dist;
	Index Path;
}TableEntry;

//vertices are numbered from 0
typedef struct _Table{
	TableEntry table[NumVertex];
	int capacity;
}Table;

void ReadGraph(ptrGraph G, Table *T);
Table *InitTable(ElemType x, ptrGraph G, Table *T);
Index FindSmallestDistance(Table *T);
void Dijkstra(Table *T);
int LocateVertexInTable(ElemType X, Table *T);
void PrintPath(ElemType End, Table *T);


#endif
