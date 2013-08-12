#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"
#include "fatal.h"

int main()
{
	QueueRecord *q;
	int i = 0;
	int tmp = 0;

	q = initQueue(10);
	for(i=0; i<9; i++)
	{
		enQueue(i, q);
	}

	while(!isEmpty(*q))
	{
		tmp = deQueue(q);
		printf("%d    ", tmp);
	}
	printf("\n");


	enQueue(5,q);
	enQueue(15,q);
	enQueue(25,q);
	enQueue(35,q);
	enQueue(45,q);
	while(!isEmpty(*q))
	{
		tmp = deQueue(q);
		printf("%d    ", tmp);
	}
	printf("\n");


	enQueue(51,q);
	enQueue(152,q);
	enQueue(235,q);
	enQueue(345,q);
	enQueue(455,q);
	while(!isEmpty(*q))
	{
		tmp = deQueue(q);
		printf("%d    ", tmp);
	}
	printf("\n");
	return 0;
}
