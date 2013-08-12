#ifndef GUARD_LEFTIST_HEAP_H
#define GUARD_LEFTIST_HEAP_H

typedef int ElemType;
typedef struct _TreeNode{
	ElemType Element;
	struct _TreeNode *Left;
	struct _TreeNode *Right;
	int Npl;
}TreeNode;
typedef TreeNode *PriorityQueue;
typedef TreeNode *ptrTreeNode;



PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Initialize(void);
ElemType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);


#define Insert( X, H ) ( H = Insert1( ( X ), H ) )
#define DeleteMin(H) (H = DeleteMin1(H))

PriorityQueue Insert1(ElemType x, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);



#endif