#include "queue_array.h"
#include "fatal.h"

//empty: head == tail
int isEmpty(QueueRecord q)
{
	return (q.size == 0);
}

//full: (rear+1)&capacity == front
int isFull(QueueRecord q)
{
	return (q.size == (q.capacity - 1));
}

QueueRecord *initQueue(int n)
{
	QueueRecord *q;
	q = malloc(sizeof(QueueRecord));
	if(q == NULL)
	{
		FatalError("Out of space!");
	}

	q->array = malloc(sizeof(ElemType) * n);
	if(q->array == NULL)
	{
		FatalError("Out of space!");
	}

	q->capacity = n;
	q->size = 0;
	q->head = 0;
	q->tail = 0;
	return q;

}

void disposeQueue(QueueRecord *q)
{
	free(q->array);
	free(q);
}


ElemType queueHead(QueueRecord q)
{
	return q.array[q.head];
}

ElemType queueTail(QueueRecord q)
{
	return q.array[q.tail];
}

int getQueueSize(QueueRecord q)
{
	return q.size;
}


//loop array
void enQueue(ElemType e, QueueRecord *q)
{
	if(isFull(*q))
	{
		FatalError("Queue full!\n");
	}

	(q->size)++;
	(q->tail)++;
	if(q->tail == q->capacity)
	{
		q->tail = 0;
	}

	q->array[q->tail] = e;

}

ElemType deQueue(QueueRecord *q)
{
	int result = 0;

	if(isEmpty(*q))
	{
		FatalError("Queue empty!\n");
	}

	(q->size)--;
	(q->head)++;
	if(q->head == q->capacity)
	{
		q->head = 0;
	}
	result = q->array[q->head];

	return result;

}
