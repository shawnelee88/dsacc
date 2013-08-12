#include "priority_queue.h"
#include "fatal.h"


#define MinPQSize (10) 
#define MinData (-32767)


PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;

	if(MaxElements < MinPQSize)
	{
		Error("Priority Queue size is too small.");
	}

	H = malloc(sizeof(HeapStruct));
	if(H == NULL)
	{
		FatalError("Out of space!");
	}

	H->Elements = malloc((MaxElements+1) * sizeof(ElemType));
	if(H == NULL)
	{
		FatalError("Out of space!");
	}

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;

	return H;
}


void Destroy( PriorityQueue H )
{
	free( H->Elements );
	free( H );
}

void MakeEmpty(PriorityQueue H)
{
	H->Size = 0;
}


//H->Elements[0] is a sentinal
void Insert(ElemType x, PriorityQueue H)
{
	int i;

	if(IsFull(H))
	{
		Error("Priority queue is full.");
		return;
	}

	for(i = ++H->Size; H->Elements[i/2] > x; i /= 2)
	{
		H->Elements[i] = H->Elements[i/2];
	}
	H->Elements[i] = x;
}


ElemType DeleteMin(PriorityQueue H)
{
	int i;
	int child;
	ElemType MinElement;
	ElemType LastElement;

	if(IsEmpty(H))
	{
		Error("Priority queue is empty.");
		return H->Elements[0];
	}

	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for(i = 1; i*2 <= H->Size; i = child)
	{
		//find smaller child
		child = i * 2;
		if(child != H->Size && H->Elements[child+1] < H->Elements[child])
		{
			child++;
		}

		//percolate down one level
		if(LastElement > H->Elements[child])
		{
			H->Elements[i] = H->Elements[child];
		}
		else
		{
			break;
		}
	}
	H->Elements[i] = LastElement;
	return MinElement;

}


ElemType FindMin( PriorityQueue H )
{
	if( !IsEmpty( H ) )
	{
		return H->Elements[ 1 ];
	}
	else
	{
		Error( "Priority Queue is Empty" );
		return H->Elements[ 0 ];
	}	
}


int IsEmpty( PriorityQueue H )
{
	return H->Size == 0;
}

int IsFull( PriorityQueue H )
{
	return H->Size == H->Capacity;
}

