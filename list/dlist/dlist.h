#ifndef GUARD_DLIST_H
#define GUARD_DLIST_H
#include "fatal.h"
typedef int ElemType;

typedef struct _Node{
	struct _Node *prev;
	struct _Node *next;
	ElemType data;
}Node;
typedef Node *PtrToNode;
typedef struct _DList{
	Node *head;
	Node *tail;
	int size;
}*DList;


DList MakeEmpty(DList L);
int IsEmpty(DList L);
int IsLast(PtrToNode P, DList L);
PtrToNode Find(DList L, ElemType e);  //return PtrToNode of e
int Delete(DList L, ElemType e);  
//delete e first occured in L; do nothing if e is not in the DList L

void Insert(DList L, ElemType e, PtrToNode P);  //insert after P
void DeleteList(DList L);
PtrToNode Advance(PtrToNode P);
ElemType Retrieve(PtrToNode P);
void PrintList(DList L);

#endif


