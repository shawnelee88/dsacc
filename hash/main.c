#include <stdio.h>
#include <stdlib.h>
#include "hash_sep.h"
#include "fatal.h"

#define NumItems 400

int main( )
{
	ptrHashTable H;
	Position P;
	int i;
	int j;
	int CurrentSize;

	H = InitializeTable( CurrentSize = 13 );

	for( i = 0, j = 0; i < NumItems; i++, j += 71 )
	{
		Insert( j, H );
	}

	Delete(H, j - 71);  //delete 28329 from hashtable which may cause error

	for( i = 0, j = 0; i < NumItems; i++, j += 71 )
	{
		if((P = Find(j, H)) == NULL || Retrieve(P) != j)
		{
			printf("Error at %d\n", j);
		}
	}

		
	for(i = 0; i < H->TableSize; i++)
	{
		printf("TheLists[%d]:", i);
		PrintList(H->TheLists[i]);
		printf("**************************************\n");
	}
	printf( "End of program.\n" );
	return 0;
}
