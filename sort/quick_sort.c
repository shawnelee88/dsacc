#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "sort.h"

#define Cutoff (3)

void QuickSort(ElemType A[], int N)
{
	QSort(A, 0, N - 1);
}


/*return median of left, center and right*/
/*order these and hide the pivot*/
ElemType Median3(ElemType A[], int Left, int Right)
{
	int Center = (Left + Right)/2;

	if(A[Left] > A[Center]){
		Swap(&A[Left], &A[Center]);
	}

	if(A[Left] > A[Right]){
		Swap(&A[Left], &A[Right]);
	}

	if(A[Center] > A[Right]){
		Swap(&A[Center], &A[Right]);
	}

	/*Invariant: A[Left] <= A[Center] <= A[Right]*/
	Swap(&A[Center], &A[Right - 1]);  /*hide pivot*/
	return A[Right - 1];  /*return pivot*/
}


void QSort(ElemType A[], int Left, int Right)
{
	int i, j;
	ElemType Pivot;

	if(Left + Cutoff <= Right){
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for(;;){
			while(A[++i] < Pivot){}  //Left+1
			while(A[--j] > Pivot){}  //Right-2
			if(i < j){
				Swap(&A[i], &A[j]);
			}else{
				break;
			}
		}
		Swap(&A[i], &A[Right - 1]);  /*restore pivot*/

		QSort(A, Left, i - 1);  //QSort the left half 
		QSort(A, i + 1, Right);  //QSort the right half
	}else{  /*Do an insertion sort on the subarray if subarray is small*/
		InsertionSort(A + Left, Right - Left + 1);
	}
}



/*places the kth smallest element in the kth position*
/*because arrays start at 0, this will be k - 1 */
void QSelect(ElemType A[], int k, int Left, int Right)
{
	int i, j;
	ElemType Pivot;

	if(Left + Cutoff <= Right){
		Pivot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for(;;){
			while(A[++i] < Pivot){}
			while(A[--j] > Pivot){}
			if(i < j){
				Swap(&A[i], &A[j]);
			}else{
				break;
			}
		}

		Swap(&A[i], &A[Right - 1]);  //restore pivot

		if(k <= i){
			QSelect(A, k, Left, i - 1);
		}else if(k > i + 1){
			QSelect(A, k, i + 1, Right);
		}
	}else{  /*do an insertion sort on the subarray if it is small array*/
		InsertionSort(A + Left, Right - Left + 1);
	}
}

