#ifndef GUARD_STACKARR_H
#define GUARD_STACKARR_H

#define MINSTACKSIZE 5

typedef int ElemType;

typedef struct _stackRecord {
	ElemType *array;
	int capacity;
	int topOfStack;
} stackRecord;
typedef stackRecord *Stack;

Stack initStack(int maxElements);
void makeEmpty(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);
void push(ElemType e, Stack s);
ElemType pop(Stack s);
void disposeStack(Stack s);
ElemType top(Stack s);

#endif