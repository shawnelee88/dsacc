#include "binomial_queue.h"
#include "fatal.h"

BinQueue Initialize(void)
{
	BinQueue H;
	int i;

	H = malloc(sizeof(Collection));
	if(H == NULL){
		FatalError("Out of space.");
	}
	H->CurrentSize = 0;
	for(i = 0; i < MaxTrees; i++){
		H->TheTrees[i] = NULL;
	}
	return H;
}

static void DestroyTree(BinTree T)
{
	if(T != NULL){
		DestroyTree(T->LeftChild);
		DestroyTree(T->NextSibling);
		free(T);
	}
}

void Destroy(BinQueue H)
{
	int i;

	for(i = 0; i < MaxTrees; i++){
		DestroyTree(H->TheTrees[i]);
	}
}

BinQueue MakeEmpty(BinQueue H)
{
	int i;

	Destroy(H);
	for(i = 0; i < MaxTrees; i++){
		H->TheTrees[i] = NULL;
	}
	H->CurrentSize = 0;
	return H;

}


BinQueue Insert(ElemType x, BinQueue H)
{
	BinTree NewNode;
	BinQueue OneItem;

	NewNode = malloc(sizeof(BinNode));
	if(NewNode == NULL){
		FatalError("Out of space.");
	}

	NewNode->Element = x;
	NewNode->NextSibling = NULL;
	NewNode->LeftChild = NULL;

	OneItem = Initialize();
	OneItem->CurrentSize = 1;
	OneItem->TheTrees[0] = NewNode;
	return Merge(H, OneItem);
}

ElemType FindMin(BinQueue H)
{
	int i;
	ElemType MinItem;

	if(IsEmpty(H)){
		Error("Empty binomial queue.");
		return 0;
	}

	MinItem = Infinity;
	for(i = 0; i < MaxTrees; i++){
		if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem){
			MinItem = H->TheTrees[i]->Element;
		}
	}
	return MinItem;
}

//return the result of merging equal-sized T1 and T2
BinTree CombineTrees(BinTree T1, BinTree T2)
{
	if(T1->Element > T2->Element){
		return CombineTrees(T2, T1);
	}
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}

//merge two binomial queues
//not optimized for early termination
//H1 contains merged result
BinQueue Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1;
	BinTree T2;
	BinTree Carry = NULL;
	int i;
	int j;

	if(H1->CurrentSize + H2->CurrentSize > Capacity){
		Error("Merge would exceed capacity.");
	}

	H1->CurrentSize += H2->CurrentSize;
	for(i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2){
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[i];

		switch (!!T1 + 2*(!!T2) + 4*(!!Carry)){
			case 0://no trees
			case 1://only H1
				break;
			case 2://only H2
				H1->TheTrees[i] = T2;
				H2->TheTrees[i] = NULL;
				break;
			case 3://H1 and H2
				Carry = CombineTrees(T1, T2);
				H1->TheTrees[i] = NULL;
				H2->TheTrees[i] = NULL;
				break;
			case 4:
				H1->TheTrees[i] = Carry;
				Carry = NULL;
				break;
			case 5://H1 and Carry
				Carry = CombineTrees(T1, Carry);
				H1->TheTrees[i] = NULL;
				break;
			case 6://H2 and Carry
				Carry = CombineTrees(T2, Carry);
				H2->TheTrees[i] = NULL;
				break;
			case 7://all trees
				H1->TheTrees[i] = Carry;
				Carry = CombineTrees(T1, T2);
				H2->TheTrees[i] = NULL;
				break;
			default:
				break;
		}
	}

	return H1;
}


ElemType DeleteMin(BinQueue H)
{
	int i;
	int j;
	int MinTree;  //the tree with the minimum item
	BinQueue DeletedQueue;
	Position DeletedTree;
	Position OldRoot;
	ElemType MinItem;

	if(IsEmpty(H)){
		Error("Empty Binomial queue.");
		return -Infinity;
	}

	MinItem = Infinity;
	for(i = 0; i < MaxTrees; i++){
		if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem){
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	}

	DeletedTree = H->TheTrees[MinTree];
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot);

	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) + 1;
	for(j = MinTree - 1; j >= 0; j--){
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}

	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;

	Merge(H, DeletedQueue);
	return MinItem;
}

int IsEmpty(BinQueue H)
{
	return H->CurrentSize == 0;
}