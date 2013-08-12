#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"
#include "fatal.h"

int main()
{
	DisjSet S;
	int i, j, k, Set1, Set2;

	Initialize(S);
	SetUnion(S, 1, 2);
	SetUnion(S, 1, 3);
	SetUnion(S, 3, 4);
	SetUnion(S, 1, 5);
	SetUnion(S, 5, 6);
	SetUnion(S, 5, 7);
	SetUnion(S, 7, 8);
	SetUnion(S, 1, 9);
	SetUnion(S, 9, 10);
	SetUnion(S, 9, 11);
	SetUnion(S, 9, 13);
	SetUnion(S, 11, 12);
	SetUnion(S, 13, 14);
	SetUnion(S, 13, 15);
	SetUnion(S, 15, 16);
	

	i = Find(16, S);
	j = Find2(16, S);
	j = Find2(15, S);
	j = Find2(14, S);
	//j = 1;
	//k = 1;
	//while(k <= 8){
	//	j = 1;
	//	while(j < NumSets){
	//		Set1 = Find(j, S);
	//		Set2 = Find(j + k, S);
	//		SetUnion(S, Set1, Set2);
	//		j += 2 * k;
	//	}
	//	k *= 2;
	//}

	//i = 1;
	//for(i = 1; i <= NumSets; i++){
	//	Set1 = Find(i, S);
	//	printf("%d**", Set1);
	//}
	printf("\n");
	return 0;
}