#include <stdio.h>
#include <stdlib.h>
#include "fatal.h"
#include "hash_quad.h"

#define MinTableSize (10)

static int NextPrime( int N )
{
	int i;

	if( N % 2 == 0 )
		N++;
	for( ; ; N += 2 )
	{
		for( i = 3; i * i <= N; i += 2 )
		{
			if( N % i == 0 )
				goto ContOuter;  /* Sorry about this! */
		}
		return N;
ContOuter: ;
	}
}


//not using "goto" statement
static int NextPrime2( int N )
{
	int i;
	int flag = 0;

	if( N % 2 == 0 )
		N++;
	for( ; ; N += 2 )
	{
		for( i = 3; i * i <= N; i += 2 )
		{
			if( N % i == 0 )
			{
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
				continue;
			}			
		}

		if(flag == 0)
		{
			return N;
		}
		else
		{
			continue;
		}
	}
}

unsigned int Hash(int key, int TableSize)
{
	return key % TableSize;;
}

ptrHashTable InitializeTable(int TableSize)
{
	ptrHashTable H;
	int i;

	if(TableSize < MinTableSize)
	{
		Error("Table Size too small.");
		return NULL;
	}

	H = malloc(sizeof(HashTable));
	if(H == NULL)
	{
		FatalError("Out of space!");
	}

	H->TableSize = NextPrime(TableSize);
	H->TheCells = malloc(sizeof(Cell) * H->TableSize);
	if(H->TheCells == NULL)
	{
		FatalError("Out of space!");
	}

	for(i = 0; i < H->TableSize; i++)
	{
		H->TheCells[i].Info = Empty;
	}

	return H;
}


void DestroyTable(ptrHashTable H)
{
	free(H->TheCells);
	free(H);
}



Position Find(ElemType key, ptrHashTable H)
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(key, H->TableSize);
	while((H->TheCells[CurrentPos].Info != Empty) && 
		  (H->TheCells[CurrentPos].Element != key))
	{
		CurrentPos = CurrentPos + 2 * (++CollisionNum) - 1;
		if(CurrentPos >= H->TableSize)
		{
			CurrentPos = CurrentPos - H->TableSize;
		}
	}

	return CurrentPos;
}





void Insert(ElemType key, ptrHashTable H)
{
	Position Pos;

	Pos = Find(key, H);
	if(H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = key;
	}
}



ptrHashTable Rehash(ptrHashTable H)
{
	
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(OldSize*2);
	for(i = 0; i < OldSize; i++)
	{
		if(OldCells[i].Info == Legitimate)
		{
			Insert(OldCells[i].Element, H);
		}
	}
	free(OldCells);

	return H;
}


void Delete(ptrHashTable H, ElemType key)
{
	Position Pos;
	
	Pos = Find(key, H);
	if(H->TheCells[Pos].Element != key)  //not in the hashtable
	{
		Error("Element %d is not in the hashtable, can not perform delete!");
	}
	else  //element is in the hashtable
	{
		H->TheCells[Pos].Info = Deleted;
		H->TheCells[Pos].Element = 0;
	}
}



ElemType Retrieve(Position P, ptrHashTable H)
{
	return H->TheCells[P].Element;
}