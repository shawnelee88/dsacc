#include "sort.h"

#define LeftChild(i) (2*(i) + 1)

void PercDown(ElemType A[], int N, int i)
{
	int Child;
	ElemType Tmp;

	for(Tmp = A[i]; LeftChild(i) < N; i = Child){
		Child = LeftChild(i);
		if(Child != N - 1 && A[Child + 1] > A[Child]){  //rchild > lchild
			Child++;
		}
		if(Tmp < A[Child]){
			A[i] = A[Child];
		}else{
			break;
		}
	}
	A[i] = Tmp;
}




void HeapSort(ElemType A[], int N)
{
	int i;

	for(i = N/2; i >= 0; i--){  //BuildHeap
		PercDown(A, N, i);
	}
	for(i = N - 1; i > 0; i--){
		Swap(&A[0], &A[i]);  //DeleteMax
		PercDown(A, i, 0);
	}
}