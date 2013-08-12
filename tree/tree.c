#include "tree.h"
#include <stdlib.h>
#include "fatal.h"

BSearchTree MakeEmpty( BSearchTree T )
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}



Position Find( ElemType x, BSearchTree T )
{
	if(T == NULL)
	{
		return NULL;
	}
	if(x < T->Element)
	{
		return Find(x, T->Left);
	}
	else if(x > T->Element)
	{
		return Find(x, T->Right);
	}
	else
	{
		return T;
	}
}


//recursion at the end
Position FindMin( BSearchTree T )
{
	if(T == NULL)
	{
		return NULL;
	}
	else if(T->Left == NULL)
	{
		return T;
	}
	else
	{
		return FindMin(T->Left);
	}
}
//recursion at the end -> loop
Position FindMin2(BSearchTree T)
{
	if(T != NULL)
	{
		while(T->Left != NULL)
		{
			T = T->Left;
		}
	}
	return T;
}



Position FindMax( BSearchTree T )
{
	if(T == NULL)
	{
		return NULL;
	}
	else if(T->Right == NULL)
	{
		return T;
	}
	else
	{
		return FindMax(T->Right);
	}
}

Position FindMax2(BSearchTree T)
{
	if(T != NULL)
	{
		while(T->Right != NULL)
		{
			T = T->Right;
		}
	}
	return T;
}


BSearchTree Insert( ElemType x, BSearchTree T )
{
	if(T == NULL)  //empty tree
	{
		T = malloc(sizeof(TreeNode));
		if(T == NULL)
		{
			FatalError("Out of space!");
		}
		
		T->Element = x;
		T->Left = NULL;
		T->Right = NULL;
	}
	else if(x < T->Element)
	{
		T->Left = Insert(x, T->Left);
	}
	else if(x > T->Element)
	{
		T->Right = Insert(x, T->Right);
	}

	return T;
}

BSearchTree Delete( ElemType x, BSearchTree T )
{
	Position TmpCell;

	if(T == NULL)
	{
		Error("Element not found.");
	}
	else if(x < T->Element)
	{
		T->Left = Delete(x, T->Left);
	}
	else if(x > T->Element)
	{
		T->Right = Delete(x, T->Right);
	}
	else if(T->Left && T->Right)  //2 children
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else  // zero or 1 child
	{
		TmpCell = T;
		if(T->Left == NULL)
		{
			T = T->Right;
		}
		else if(T->Right = NULL)
		{
			T = T->Left;
		}
		free(TmpCell);
	}

	return T;
}


ElemType Retrieve(Position P)
{
	if(P == NULL)
	{
		return -1;
	}
	else
	{
		return P->Element;
	}
}



void InOrderTraverse( BSearchTree T )
{
	if(T != NULL)
	{
		InOrderTraverse(T->Left);
		printf("%d    ", Retrieve(T));
		InOrderTraverse(T->Right);
	}
}


void PreOrderTraverse( BSearchTree T )
{
	if(T != NULL)
	{
		printf("%d    ", Retrieve(T));
		PreOrderTraverse(T->Left);
		PreOrderTraverse(T->Right);
	}
}

void PostOrderTraverse( BSearchTree T )
{
	if(T != NULL)
	{
		PostOrderTraverse(T->Left);
		PostOrderTraverse(T->Right);
		printf("%d    ", Retrieve(T));
	}
}

