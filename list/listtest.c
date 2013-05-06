#include <stdio.h>
#include "list.h"


int main()
{
	List L;
	Position P;
	int i;
	
	L = MakeEmpty(NULL);
	P = Header(L);
	PrintList(L);
	
	for(i = 0; i < 10; i++){
		Insert(L, i, P);
		PrintList(L);
		P = Advance(P);
	}
	for(i = 0; i < 10; i+=2){
		Delete(L, i);
		PrintList(L);
	}
	
	printf("Finished Deletions\n");
	PrintList(L);
	DeleteList(L);
	PrintList(L);
	return 0;
	
	
}