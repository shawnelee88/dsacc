/************************************************************************/
/* 给定一个整数X和整数A0--An-1,后者已经预先排序并在内存中
/* 求使得Ai=X的下标i，若x不在数据中，则返回-1
/************************************************************************/

#include "BinarySearch.h"


int BinarySearch(const int A[], int x, int N)
{
	int low = 0;
	int mid = 0;
	int high = N - 1;

	while(low <= high){
		mid = (low + high)/2;
		if(A[mid] < x){
			low = mid + 1;
		}else if(A[mid] > x){
			high = mid - 1;
		}else{
			return mid;
		}
	}

	return -1;
}