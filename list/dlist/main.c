#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main()
{
	DList L;
	L = MakeEmpty(NULL);
	Insert(L, 1, NULL);
	Insert(L, 2, NULL);
	Insert(L, 3, NULL);
	Insert(L, 4, NULL);
	Insert(L, 5, NULL);
	Insert(L, 6, NULL);
	Insert(L, 7, NULL);
	Insert(L, 8, NULL);
	PrintList(L);
	Delete(L, 5);
	PrintList(L);
	DeleteList(L);
}