#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

int main()
{
	AvlTree T = NULL;
	Position P = NULL;
	int i = 0;
	T = MakeEmpty(T);
	for(i = 1; i < 8; i++){
		T = Insert(i, T, T);
	}
	//T = Insert(1, T, NULL);
	//T = Insert(2, T, T);
	//T = Insert(3, T, T);
	//T = Insert(4, T, T);
	//T = Insert(5, T, T);
	//T = Insert(6, T, T);
	//T = Insert(7, T, T);
	InOrderTraverse(T);
	printf("\n");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	//P = FindMin(T);
	//printf("min = %d\n", Retrieve(P));
	//P = FindMax(T);
	//printf("max = %d\n", Retrieve(P));


	//for(i = 7; i > 0; i--){
	//	T = Delete(i, T);
	//}
	T = Delete(4, T);  //test when node has two child
	PostOrderTraverse(T);
	printf("\n");




}