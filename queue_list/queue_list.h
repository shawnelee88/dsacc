#ifndef GUARD_QUEUELIST_H
#define GUARD_QUEUELIST_H

#define MAXSIZE 1000

typedef int ElemType;

typedef struct _queueNode
{
	ElemType item;
	struct _queueNode *next;
}QueueNode;

typedef QueueNode *ptrQueueNode;
typedef struct _queue
{
	ptrQueueNode head;
	ptrQueueNode tail;
	int size;
}*Queue;


int isEmpty(Queue q);
ptrQueueNode queueHead(Queue q);
ptrQueueNode queueTail(Queue q);
int getQueueSize(Queue q);
Queue initQueue();
void disposeQueue(Queue q);
void enQueue(ElemType e, Queue q);
ElemType deQueue(Queue q);


#endif // GUARD_QUEUELIST_H
