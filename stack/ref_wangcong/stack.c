#include "stack.h"

p_stack_t stack_create(void){
	p_stack_t Stack;

	Stack=(p_stack_t)malloc(sizeof(stack_t));
	if(Stack==NULL){
		errno=ENOMEM;
		return NULL;
		}
	Stack->top=(p_slnode_t)malloc(sizeof(slnode_t));
	if(Stack->top==NULL){
		free(Stack);
		errno=ENOMEM;
		return NULL;
		}
	Stack->size=0;
	Stack->top->pdata=NULL;
	Stack->top->next=NULL;
	Stack->base=Stack->top;
	return Stack;
	}

int push(p_stack_t Stack,void* pitem,size_t n){
	p_slnode_t p;
	void *newp;

	if(Stack==NULL){
		errno=EINVAL;
		return -1;
		}
	newp=malloc(n);
	if(!newp){
		errno=ENOMEM;
		return -1;
		}
	if(Stack->size!=0){
		p=(p_slnode_t)malloc(sizeof(slnode_t));
		if(p==NULL){
			free(newp);
			errno=ENOMEM;
			return -1;
			}
		memcpy(newp,pitem,n);
		p->pdata=newp;
		p->next=Stack->top;
		Stack->top=p;
		Stack->size++;
	}else{
		memcpy(newp,pitem,n);
		Stack->top->pdata=newp;
        		Stack->size++;
        	}
	return 0;
	}

void pop(p_stack_t Stack){
	p_slnode_t p;

	if(Stack==NULL || Stack->size==0){
		errno=EINVAL;
		return;
		}
	p=Stack->top;
	Stack->top=Stack->top->next;
	free(p->pdata);
	free(p);
	Stack->size--;
	}

void stack_destroy(p_stack_t Stack){
	register int count;
	if(Stack==NULL){
		errno=EINVAL;
		return;
		}
	for(count=Stack->size;count>=1;count--)
		pop(Stack);
	free(Stack);
	}

void* top(p_stack_t Stack){
	if(Stack==NULL || Stack->size==0){
		errno=EINVAL;
		return NULL;
		}
	return Stack->top->pdata;
	}

int isempty(p_stack_t Stack){
	if(Stack==NULL){
		errno=EINVAL;
		return -1;
		}
	return Stack->size==0;
	}

