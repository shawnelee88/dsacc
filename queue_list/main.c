#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"
#include "fatal.h"

int main()
{
	Queue q;
	int tmp = 0;
	int i = 0;

	q = initQueue();
	printf("QueueSize is %d after initQueue!\n", getQueueSize(q));
	for(i=0; i<50; i++)
	{
		enQueue(i, q);
	}
	printf("QueueSize is %d after enQueue 50 elements!\n", getQueueSize(q));


	while(!isEmpty(q))
	{
		tmp = deQueue(q);
		printf("%d    ", tmp);
	}
	printf("QueueSize is %d after deQueue 50 elements!\n", getQueueSize(q));

	disposeQueue(q);
	return 0;
}
