#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


#define MaxSize 7000
int Arr1[ MaxSize ];
int Arr2[ MaxSize ];

int main()
{
	int i;

	//for(i = 0; i < 10; i++){
	//	Permute( Arr2, MaxSize );
	//	Copy( Arr1, Arr2, MaxSize );
	//	InsertionSort( Arr1, MaxSize );
	//	Checksort( Arr1, MaxSize );


	//	Copy( Arr1, Arr2, MaxSize );
	//	ShellSort( Arr1, MaxSize );
	//	Checksort( Arr1, MaxSize );

	//	Copy( Arr1, Arr2, MaxSize );
	//	HeapSort( Arr1, MaxSize );
	//	Checksort( Arr1, MaxSize );

	//	Copy( Arr1, Arr2, MaxSize );
	//	MergeSort( Arr1, MaxSize );
	//	Checksort( Arr1, MaxSize );

	//	Copy( Arr1, Arr2, MaxSize );
	//	QuickSort( Arr1, MaxSize );
	//	Checksort( Arr1, MaxSize );

	//	Copy( Arr1, Arr2, MaxSize );
	//	QSelect( Arr1, MaxSize / 2 + 1 + i, 0, MaxSize - 1 );
	//	if( Arr1[ MaxSize / 2 + i ] != MaxSize / 2 + i){
	//		printf( "Select error: %d %d\n", MaxSize / 2 + i, Arr1[ MaxSize / 2 + i] );
	//	}else{
	//		printf( "Select works\n" );
	//	}
	//}
	
		

	/*my simple test*/
	int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	//can use any kind of sort algorithms
	BubbleSort(A, sizeof(A)/4);  
	for(i = 0; i < sizeof(A)/4; i++){
		printf("%d    ", A[i]);
	}
	
	//QSelect( A, 6, 0, 8);
}