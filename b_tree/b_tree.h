#ifndef GUARD_B_TREE_H
#define GUARD_B_TREE_H

typedef int ElemType;
typedef struct _BTreeNode
{
	int count;
	ElemType key[3];
	struct _BTreeNode *branch[4];
}BTreeNode;  //4½×BÊ÷
typedef BTreeNode *BTree;



#endif