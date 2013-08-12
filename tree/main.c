#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
	BSearchTree T = NULL;
	Position P = NULL;
	//T = MakeEmpty(T);
	//T = Insert(1, T);
	//T = Insert(2, T);
	//T = Insert(3, T);
	//T = Insert(4, T);
	//T = Insert(5, T);
	//T = Insert(6, T);
	//T = Insert(7, T);
	//InOrderTraverse(T);
	//printf("\n");
	//PreOrderTraverse(T);
	//printf("\n");
	//PostOrderTraverse(T);
	//printf("\n");

	//T = Delete(5, T);
	//T = Delete(2, T);
	//InOrderTraverse(T);
	//
	T = MakeEmpty(T);

	T = Insert(4, T);
	T = Insert(2, T);
	T = Insert(3, T);
	T = Insert(1, T);
	T = Insert(7, T);
	T = Insert(5, T);
	T = Insert(6, T);
	InOrderTraverse(T);
	printf("\n");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	P = FindMin(T);
	printf("min = %d\n", Retrieve(P));
	P = FindMax(T);
	printf("max = %d\n", Retrieve(P));
}