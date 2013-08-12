#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackarr.h"

int main()
{
	Stack s;
	int i = 0;
	int tmp = 0;

	s = initStack(12);
	for(i=0; i<10; i++)
	{
		push(i, s);
	}

	while(!isEmpty(s))
	{
		tmp = pop(s);
		printf("%d    ", tmp);
	}

	disposeStack(s);
	return 0;
}
