#ifndef GUARD_PRIORITY_QUEUE_H
#define GUARD_PRIORITY_QUEUE_H

typedef int ElemType;
typedef struct _HeapStruct
{
	int Capacity;
	int Size;
	ElemType *Elements;
}HeapStruct;
typedef HeapStruct *PriorityQueue;


PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElemType x, PriorityQueue H);
ElemType DeleteMin(PriorityQueue H);
ElemType FindMin(PriorityQueue H);
int IsFull(PriorityQueue H);
int IsEmpty(PriorityQueue H);




#endif