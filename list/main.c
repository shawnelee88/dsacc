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


	//test for insert operation
	for(i = 0; i < 10; i++){
		Insert(L, i, P);
		P = Advance(P);
	}
	PrintList(L);
	P = Find(L, 5);  //test for Find, Find2, Find3 operations
	//P = Find2(L, 5)
	//P = Find3(L, 5);
	Insert(L, 99, P);
	PrintList(L);    //test for PrintList operation

	for(i = 0; i < 10; i+=2){
		Delete(L, i);	
	}
	PrintList(L);

	DeleteList(L);
	PrintList(L);
	return 0;


}