#include "sort.h"
#include "fatal.h"

void BubbleSort(ElemType A[], int N)
{
	int i, j, tmp;

	for(i = 0; i < N - 1; i++){
		for(j = 0; j < N - 1 - i; j++){
			if(A[j] > A[j+1]){
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}
}