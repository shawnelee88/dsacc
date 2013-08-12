#include "hash_sep.h"
#include "fatal.h"



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

ptrHashTable InitializeTable(int TableSize)
{
	ptrHashTable H;
	int i;

	if(TableSize < MinTableSize)
	{
		Error( "Table size too small" );
		return NULL;
	}
	
	/*allocate table*/
	H = malloc(sizeof(HashTable));
	if(H == NULL)
	{
		FatalError("Out of space!");
	}

	H->TableSize = NextPrime2(TableSize);

	/*allocate array of lists*/
	H->TheLists = malloc(sizeof( List ) * H->TableSize);
	if(H->TheLists == NULL)
	{
		FatalError("Out of space!");
	}

	/*allocate list headers*/
	for(i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = malloc(sizeof(ListNode));
		if(H->TheLists[i] == NULL)
		{
			FatalError("Out of space!");
		}
		else
		{
			H->TheLists[i]->Next = NULL;
		}
	}

	return H;
}

void DestroyTable(ptrHashTable H)
{
	List L;
	Position P;
	Position TmpCell;
	int i;

	for(i = 0; i < H->TableSize; i++)
	{
		L = H->TheLists[i];
		P = L->Next;
		while(P != NULL)
		{
			TmpCell = P->Next;
			P = P->Next;
			free(TmpCell);
		}
		free(L);
	}
	free(H->TheLists);
	free(H);
}

Position Find(ElemType key, ptrHashTable H)
{
	List L;
	Position P;

	L = H->TheLists[Hash(key, H->TableSize)];
	P = L->Next;
	while(P != NULL && P->Element != key)
	{
		P = P->Next;
	}

	return P;
}

Position FindPrevious(ElemType key, ptrHashTable H)
{
	List L;
	Position P;

	L = H->TheLists[Hash(key, H->TableSize)];
	P = L;
	while(P->Next != NULL && P->Next->Element != key)
	{
		P = P->Next;
	}

	return P;
}

void Insert(ElemType key, ptrHashTable H)
{
	List L;
	Position P;
	Position TmpCell;

	P = Find(key, H);
	if(P == NULL)  //not found, then insert
	{
		TmpCell = malloc(sizeof(ListNode));
		if(TmpCell == NULL)
		{
			FatalError("Out of space!");
		}
		else
		{
			L = H->TheLists[Hash(key, H->TableSize)];
			TmpCell->Next = L->Next;
			TmpCell->Element = key;
			L->Next = TmpCell;
		}
	}
	/*do nothing if already existed*/
}


ElemType Retrieve(Position P)
{
	return P->Element;
}

void Delete(ptrHashTable H, ElemType key)
{
	Position P;
	Position TmpCell;

	P = FindPrevious(key, H);	
	if(P->Next != NULL)  //found and delete from the whole HashTable
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
	/*do nothing if not found*/
}



//hash for key = int
unsigned int Hash(int key, int TableSize)
{
	return key % TableSize;;
}


//hash for key = string
unsigned int Hash2(const char *key, int TableSize)
{
	unsigned int HashVal = 0;

	while(*key != '\0')
	{
		HashVal += *key++;
	}

	return HashVal;
}


//hash for key = string
unsigned int Hash3(const char *key, int TableSize)
{
	unsigned int HashVal = 0;

	while(*key != '\0')
	{
		HashVal = (HashVal << 5) + *key++;
	}

	return HashVal;
}



void PrintList(List L)
{
	Position P = L;

	if(L->Next == NULL){
		printf("Empty list!\n");
	}else{
		do{
			P = P->Next;	
			printf("%d    ", Retrieve(P));
		}while(P->Next != NULL);
		printf("\n");
	}
}