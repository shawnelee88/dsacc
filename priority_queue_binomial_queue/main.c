#include <stdio.h>
#include <stdlib.h>
#include "binomial_queue.h"
#include "fatal.h"

#define MaxSize 12000
int main()
{
	BinQueue H;
	BinQueue H2;
    int i, j;
    ElemType AnItem;

	H = Initialize();
	H2 = Initialize();
	/*test for insert and merge*/
	//Insert(24, H);
	//Insert(65, H);
	//Insert(12, H);
	//Insert(21, H);

	//Insert(16, H2);
	//Insert(18, H2);
	//Insert(14, H2);
	//Insert(26, H2);
	//Merge(H, H2);

	/*test for insert and deletemin*/
	Insert(16, H);
	Insert(18, H);
	Insert(14, H);
	Insert(26, H);
	Insert(24, H);
	Insert(65, H);
	Insert(12, H);
	Insert(21, H);

	
	Insert(24, H);
	Insert(65, H);
	Insert(23, H);
	Insert(51, H);
	Insert(13, H);
	DeleteMin(H);

	//Insert(, H);
	//Insert(16, H);
	//Insert(18, H);
	//Insert(12, H);
	
    //H = Initialize( );
    //for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
    //{
	   // H = Insert( j, H );
    //}

    printf( "Done...\n" );
}