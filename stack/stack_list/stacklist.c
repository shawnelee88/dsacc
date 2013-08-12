#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

int isEmpty(Stack s)
{
	return s->next == NULL;
}


Stack initStack()
{
	Stack s;

	s = malloc(sizeof(Node));
	if(s == NULL){
		printf("Out of space!");
		exit(1);
	}

	s->next = NULL;
	makeEmpty(s);
	return s;
}


void makeEmpty(Stack s)
{
	if(s == NULL){
		printf("Must use initStack first");
		exit(1);
	}
	else{
		while(!isEmpty(s)){
			pop(s);
		}
	}
}

//insert before
void push(ElemType e, Stack s)
{
	PtrToNode tmp;

	tmp = malloc(sizeof(Node));
	if(tmp == NULL){
		printf("Out of space!");
		exit(1);
	}

	tmp->item = e;
	tmp->next = s->next;
	s->next = tmp;
}


ElemType pop(Stack s)
{
	ElemType tmp = 0;
	PtrToNode topcell;

	if(isEmpty(s)){
		printf("Empty stack!");
		return -1;
	}else{
		tmp = s->next->item;
		topcell = s->next;
		s->next = s->next->next;
		free(topcell);
		return tmp;
	}
}

ElemType top(Stack s)
{
	if(isEmpty(s)){
		printf("Empty stack!");
		return -1;
	}else{
		return s->next->item;
	}
}

void disposeStack(Stack s)
{
	if(s == NULL){
		printf("\nCan't disposeStack!\n");
	}
	makeEmpty(s);
	free(s);
}