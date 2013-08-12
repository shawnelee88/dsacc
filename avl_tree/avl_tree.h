#ifndef GUARD_AVLTREE_H
#define GUARD_AVLTREE_H

typedef int ElemType;
typedef struct _AvlNode
{
	ElemType Element;
	struct _AvlNode *Left;
	struct _AvlNode *Right;
	struct _AvlNode *Parent;    //used for deletion
	int Height;		
	int bf;    //balance factor: height(T->Left)-height(T->Right)
}AvlNode;
typedef AvlNode *AvlTree;
typedef AvlNode *Position;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElemType x, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElemType x, AvlTree T, AvlTree Pre);
AvlTree Delete(ElemType x, AvlTree T);
ElemType Retrieve(Position P);
void InOrderTraverse(AvlTree T);
void PreOrderTraverse(AvlTree T);
void PostOrderTraverse(AvlTree T);
int Height(Position P);
Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K2);
Position DoubleRotateWithLeft(Position K3);
Position DoubleRotateWithRight(Position K3);

#endif