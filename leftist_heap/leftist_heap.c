#include "leftist_heap.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue Initialize(void)
{
	return NULL;
}

static void SwapChildren(PriorityQueue H)
{
	ptrTreeNode tmp;
	
	tmp = H->Left;
	H->Left = H->Right;
	H->Right = tmp;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if(H1->Left == NULL){  //single node(leftist's left child npl >= right child npl)
		H1->Left = H2;
	}else{
		H1->Right = Merge(H1->Right, H2);
		if(H1->Left->Npl < H1->Right->Npl){
			SwapChildren(H1);
		}
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if(H1 == NULL){
		return H2;
	}
	if(H2 == NULL){
		return H1;
	}
	if(H1->Element < H2->Element){
		return Merge1(H1, H2);
	}else{
		return Merge1(H2, H1);
	}
}

ElemType FindMin(PriorityQueue H)
{
	return H->Element;
}

int IsEmpty(PriorityQueue H)
{
	if(H == NULL){
		return 1;
	}else{
		return 0;
	}
}

//insert is a kind of merge
PriorityQueue Insert1(ElemType x, PriorityQueue H)
{
	PriorityQueue SingleNode;

	SingleNode = malloc(sizeof(TreeNode));
	if(SingleNode == NULL){
		FatalError("Out of space!");
	}else{
		SingleNode->Element = x;
		SingleNode->Npl = 0;
		SingleNode->Left = NULL;
		SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}


PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap;
	PriorityQueue RightHeap;

	if(IsEmpty(H)){
		Error("Priority Queue is empty.");
		return H;
	}

	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}