/************************************************************************/
/* ����һ������X������A0--An-1,�����Ѿ�Ԥ���������ڴ���
/* ��ʹ��Ai=X���±�i����x���������У��򷵻�-1
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