#ifndef GUARD_TREE_H
#define GUARD_TREE_H

typedef int ElemType;
typedef struct _TreeNode
{
	ElemType Element;
	struct _TreeNode *Left;
	struct _TreeNode *Right;
}TreeNode;
typedef TreeNode *Position;
typedef TreeNode *BSearchTree;


BSearchTree MakeEmpty(BSearchTree T);
Position Find(ElemType x, BSearchTree T);
Position FindMin(BSearchTree T);
Position FindMax(BSearchTree T);
BSearchTree Insert(ElemType x, BSearchTree T);
BSearchTree Delete(ElemType x, BSearchTree T);
ElemType Retrieve(Position P);
void InOrderTraverse(BSearchTree T);
void PreOrderTraverse(BSearchTree T);
void PostOrderTraverse(BSearchTree T);



#endif