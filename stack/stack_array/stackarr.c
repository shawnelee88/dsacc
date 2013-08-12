#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackarr.h"

Stack initStack(int maxElements)
{
	Stack s = NULL;

	if(maxElements < MINSTACKSIZE)
	{
		Error("Stack too small!");
	}

	s = malloc(sizeof(stackRecord));
	if(s == NULL)
	{
		FatalError("Out of space!");
	}

	s->array = malloc(maxElements * sizeof(ElemType));
	if(s->array == NULL)
	{
		FatalError("Out of space!");
	}

	s->capacity = maxElements;
	makeEmpty(s);
	return s;
}

void makeEmpty(Stack s)
{
	if(s == NULL)
	{
		Error("Must initStack first!\n");
	}
	else
	{
		s->topOfStack = -1;
	}

}



int isEmpty(Stack s)
{
	if(s == NULL)
	{
		Error("Must initStack first!\n");
	}
	else
	{
		return s->topOfStack == -1;
	}

}

int isFull(Stack s)
{
	if(s == NULL)
	{
		Error("Must initStack first!\n");
	}
	else
	{
		return s->topOfStack == s->capacity - 1;
	}
}


void push(ElemType e, Stack s)
{
	if(isFull(s))
	{
		Error("Stack is full!\n");
	}
	else
	{
		(s->topOfStack)++;
		s->array[s->topOfStack] = e;
	}
}


ElemType pop(Stack s)
{
	ElemType tmp;
	if(isEmpty(s))
	{
		Error("Stack is empty!\n");
	}
	else
	{
		tmp = s->array[s->topOfStack];
		(s->topOfStack)--;
		return tmp;
	}
}

void disposeStack(Stack s)
{
	if(s == NULL)
	{
		Error("Must initStack first!\n");
	}
	else
	{
		free(s->array);
		free(s);
	}
}

ElemType top(Stack s)
{
	if(isEmpty(s))
	{
		Error("Empty stack!\n");
	}
	else
	{
		return s->array[s->topOfStack];
	}
}


