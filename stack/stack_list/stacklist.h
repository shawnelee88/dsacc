#ifndef guard_stack_h
#define guard_stack_h


typedef int ElemType;

typedef struct _Node{
	ElemType item;
	struct _Node *next;
}Node;

typedef Node *Stack;
typedef Node *PtrToNode;

Stack initStack();
void makeEmpty(Stack s);
int isEmpty(Stack s);
int isFull(Stack s);
void push(ElemType e, Stack s);
ElemType pop(Stack s);
void disposeStack(Stack s);
ElemType top(Stack s);


#endif