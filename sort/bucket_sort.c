#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "fatal.h"

#define MaxSize 1000

void BucketSort(ElemType A[], int N)
{
	int i;
	int j;
	int k;
	int Buckets[MaxSize];
	
	for(i = 0; i < MaxSize; i++){
		Buckets[i] = 0;
	}

	for(i = 0; i < N; i++){
		Buckets[A[i]]++;
	}

	k = 0;
	for(j = 0; j < 1000; j++){
		if(Buckets[j] != 0){
			for(i = 0; i < Buckets[j]; i++){  //deal with same data
				//printf("%d  ", j);
				A[k++] = j;
			}
		}

		if(k == N){
			break;
		}
	}
}