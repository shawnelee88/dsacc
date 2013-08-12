#include "sort.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>


void MSort(ElemType A[], ElemType TmpArray[], int Left, int Right)
{
	int Center;

	if(Left < Right){
		Center = (Left + Right)/2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}

/*Lpos = start of left half; Rpos = start of right half*/
void Merge(ElemType A[], ElemType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while(Lpos <= LeftEnd && Rpos <= RightEnd){
		if(A[Lpos] <= A[Rpos]){
			TmpArray[TmpPos++] = A[Lpos++];
		}else{
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}

	while(Lpos <= LeftEnd){  //copy rest of first half
		TmpArray[TmpPos++] = A[Lpos++];
	}

	while(Rpos <= RightEnd){  //copy rest of second half
		TmpArray[TmpPos++] = A[Rpos++];
	}

	//copy TmpArray back
	for(i = 0; i < NumElements; i++, RightEnd--){
		A[RightEnd] = TmpArray[RightEnd];
	}
}


void MergeSort(ElemType A[], int N)
{
	ElemType *TmpArray;

	TmpArray = malloc(N * sizeof(ElemType));
	if(TmpArray == NULL){
		FatalError("Out of space!");
	}else{
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
}

