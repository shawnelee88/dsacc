#ifndef GUARD_SPLAY_TREE_H
#define GUARD_SPLAY_TREE_H

#define Infinity 30000
#define NegInfinity (-30000)

typedef int ElementType;
typedef struct _SplayNode
{
	ElementType Element;
	struct _SplayNode *Left;
	struct _SplayNode *Right;
}SplayNode;
typedef SplayNode *SplayTree;
typedef SplayNode *Position;

SplayTree MakeEmpty( SplayTree T );
SplayTree Find( ElementType X, SplayTree T );
SplayTree FindMin( SplayTree T );
SplayTree FindMax( SplayTree T );
SplayTree Initialize( void );
SplayTree Insert( ElementType X, SplayTree T );
SplayTree Remove( ElementType X, SplayTree T );
ElementType Retrieve( SplayTree T );  /* Gets root item */
SplayTree Splay( ElementType Item, Position X );


void InOrderTraverse(SplayTree T);
void PreOrderTraverse(SplayTree T);
void PostOrderTraverse(SplayTree T);
Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K2);
Position DoubleRotateWithLeft(Position K3);
Position DoubleRotateWithRight(Position K3);

#endif
