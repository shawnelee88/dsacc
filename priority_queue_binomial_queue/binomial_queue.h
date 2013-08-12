#ifndef GUARD_BINOMIAL_QUEUE_H
#define GUARD_BINOMIAL_QUEUE_H

#define MaxTrees 14
#define Capacity 16383  //stores 2^14-1 items
#define Infinity 30000
typedef int ElemType;
typedef struct _BinNode{
	ElemType Element;
	struct _BinNode *LeftChild;
	struct _BinNode *NextSibling;
}BinNode;
typedef BinNode *Position;
typedef BinNode *BinTree;
typedef struct _Collection{
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
}Collection;
typedef Collection *BinQueue;



BinQueue Initialize(void);
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);
BinQueue Insert(ElemType x, BinQueue H);
ElemType FindMin(BinQueue H);
BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElemType DeleteMin(BinQueue H);
int IsEmpty(BinQueue H);

#endif