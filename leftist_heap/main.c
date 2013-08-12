#include <stdio.h>
#include "leftist_heap.h"
#include "fatal.h"

#define MaxSize 5000

int main( )
{
	PriorityQueue H;
	PriorityQueue H2;
	PriorityQueue H3;
	PriorityQueue H4;
	int i, j;

	H = Initialize( );
	H2 = Initialize();
	H3 = Initialize();
	H4 = Initialize();
	
	Insert(17, H2);
	Insert(26, H2);
	Insert(8, H2);
	Insert(10, H);
	Insert(21, H);
	Insert(14, H);
	Insert(23, H);
	Insert(3, H);
	Merge(H, H2);


	Insert(12, H3);
	Insert(18, H3);
	Insert(24, H3);
	Insert(33, H3);
	Insert(6, H3);
	Insert(7, H4);
	Insert(37, H4);
	Insert(18, H4);
	Merge(H3, H4);

	Merge(H, H3);

	//for( i = 0, j = MaxSize/2; i < MaxSize; i++, j = ( j+17)%MaxSize ){
	//	Insert( j, H );
	//}

	//j = 0;
	//while( !IsEmpty( H ) ){
	//	if( FindMin( H ) != j++ ){
	//		printf( "Error in DeleteMin, %d\n", j );
	//	}else{
	//		H = DeleteMin1( H );
	//	}
	//		
	//}
		
	printf( "Done...\n" );
	return 0;
}