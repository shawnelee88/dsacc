#include "queue_list.h"
#include "fatal.h"




int isEmpty(Queue q)
{
	return (q->size == 0) && (q->head == NULL) && (q->tail == NULL);
}

ptrQueueNode queueHead(Queue q)
{
	if(q == NULL)
	{
		FatalError("Must initQueue first!\n");
	}

	return q->head;
}


ptrQueueNode queueTail(Queue q)
{
	if(q == NULL)
	{
		FatalError("Must initQueue first!\n");
	}
	return q->tail;
}


int getQueueSize(Queue q)
{
	if(q == NULL)
	{
		FatalError("Must initQueue first!\n");
	}

	return q->size;
}


Queue initQueue()
{
	Queue q;

	q = malloc(sizeof(struct _queue));
	if(q == NULL)
	{
		FatalError("Out of space!\n");
	}

	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

void disposeQueue(Queue q)
{
	if(q == NULL)
	{
		FatalError("Must initQueue first!\n");
	}

	while(!isEmpty(q))
	{
		deQueue(q);
	}
	free(q);
}

void enQueue(ElemType e, Queue q)
{
	ptrQueueNode node;
	ptrQueueNode tmpTail;

	if(q->size == MAXSIZE)
	{
		FatalError("Queue Full!\n");
	}

	node = malloc(sizeof(struct _queueNode));
	if(node == NULL)
	{
		FatalError("Out of space!\n");
	}

	node->item = e;
	node->next = NULL;

	if(q->size == 0)
	{
		q->head = node;
		q->tail = node;
	}
	else
	{
		tmpTail = queueTail(q);
		q->tail = node;
		tmpTail->next = node;
	}

	(q->size)++;
}



ElemType deQueue(Queue q)
{

	ptrQueueNode tmpHead;
	int result = 0;

	tmpHead = queueHead(q);
	if(q->size == 1)
	{
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		q->head = tmpHead->next;
	}

	(q->size)--;
	result = tmpHead->item;
	free(tmpHead);

	return result;
}


