#ifndef GUARD_QUEUEARRAY_H
#define GUARD_QUEUEARRAY_H


typedef int ElemType;

typedef struct _queueRecord
{
	int head;
	int tail;
	int size;
	int capacity;
	ElemType *array;
}QueueRecord;


int isEmpty(QueueRecord q);
int isFull(QueueRecord q);
ElemType queueHead(QueueRecord q);
ElemType queueTail(QueueRecord q);
int getQueueSize(QueueRecord q);
QueueRecord *initQueue(int n);
void disposeQueue(QueueRecord *q);
void enQueue(ElemType e, QueueRecord *q);
ElemType deQueue(QueueRecord *q);


#endif // GUARD_QUEUEARRAY_H