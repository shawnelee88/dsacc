#include <stdio.h>
#include <stdlib.h>
#include "hash_quad.h"


#define NumItems 400

int main( )
{
	ptrHashTable H;
	Position P;
	int i;
	int j = 0;
	int CurrentSize;

	H = InitializeTable( CurrentSize = 13 );

	for( i = 0; i < NumItems; i++, j += 71 )
	{

		if( i > CurrentSize / 2 )
		{
			H = Rehash( H );
			printf( "Rehashing...\n" );
			CurrentSize *= 2;
		}

		Insert( j, H );
	}

	Delete(H, j-71);  //cause error at 28329

	for( i = 0, j = 0; i < NumItems; i++, j += 71 )
	{
		if( Retrieve( ( P = Find( j, H ) ), H ) != j )
		{
			printf( "Error at %d\n", j );
		}
	}
	printf( "End of program.\n" );
	return 0;
}
