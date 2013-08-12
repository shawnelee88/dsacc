#include "sort.h"

void InsertionSort(ElemType A[], int N)
{
	int j;
	int P;
	ElemType Tmp;

	for(P = 1; P < N; P++){
		Tmp = A[P];
		for(j = P; j >0 && A[j-1] > Tmp; j--){
			A[j] = A[j - 1];
		}
		A[j] = Tmp;
	}
}

/*routines to test the sort*/

//assign the array and swap elements randomly
void Permute( ElemType A[ ], int N )
{
	int i;

	for( i = 0; i < N; i++ )
		A[ i ] = i;
	for( i = 1; i < N; i++ )
		Swap( &A[ i ], &A[ rand( ) % ( i + 1 ) ] );
}

void Swap(ElemType *Lhs, ElemType *Rhs)
{
	ElemType Tmp = *Lhs;
	*Lhs = *Rhs;
	*Rhs = Tmp;
}

void Checksort( ElemType A[ ], int N )
{
	int i;

	for( i = 0; i < N; i++ ){
		if( A[ i ] != i ){
			printf( "Sort fails: %d %d\n", i, A[ i ] );
		}
	}
	printf( "Check completed\n" );
}

void Copy( ElemType Lhs[ ], const ElemType Rhs[ ], int N )
{
	int i;

	for( i = 0; i < N; i++ ){
		Lhs[ i ] = Rhs[ i ];
	}	
}