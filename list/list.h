#ifndef _LIST_H
#define _LIST_H


typedef int ElemType;
typedef struct _Node{
	ElemType data;
	struct _Node *next;
}Node, *List, *Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(List L, ElemType e);  //return position of e
void Delete(List L, ElemType e);  
//delete e first occured in L; do nothing if e is not in the List L
Position FindPrevious(List L, ElemType e);  //used fot Delete
void Insert(List L, ElemType e, Position P);  //insert after P
void DeleteList(List L);
void PrintList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElemType Retrieve(Position P);


#endif