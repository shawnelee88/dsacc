#include "deque.h"

p_deque_t deque_create(void){
	p_deque_t queue;
	queue=(p_deque_t)malloc(sizeof(deque_t));
	if(queue==NULL){
		errno=ENOMEM;
		return NULL;
		}
	queue->head=(p_dlnode_t)malloc(sizeof(dlnode_t));
	if(queue->head==NULL){
		free(queue);
		errno=ENOMEM;
		return NULL;
		}
	queue->size=0;
	queue->head->pdata=NULL;
	queue->head->next=queue->head->prev=NULL;
	queue->tail=queue->head;
	return queue;
	}

int deque_isempty(p_deque_t queue){
	if(queue==NULL){
		errno=EINVAL;
		return -1;
		}
	return queue->size==0;
	}

int deque_put_head(p_deque_t queue,void* pitem,size_t n){
	p_dlnode_t new_item;
	void *newp=NULL;

	if(queue==NULL){
		errno=EINVAL;
		return -1;
		}
	newp=malloc(n);
	if(!newp){
		errno=ENOMEM;
		return -1;
		}
	if(queue->size==0){
		memcpy(newp,pitem,n);
		queue->head->pdata=newp;
		queue->size++;
		}
	else{
		new_item=(p_dlnode_t)malloc(sizeof(dlnode_t));
		if(new_item==NULL){
			free(newp);
			errno=ENOMEM;
			return -1;
			}
		memcpy(newp,pitem,n);
        		new_item->pdata=newp;
		new_item->prev=NULL;
        		new_item->next=queue->head;
		queue->head->prev=new_item;
		queue->head=queue->head->prev;
        		queue->size++;
    		}
	return 0;
	}

int deque_put_tail(p_deque_t queue,void* pitem,size_t n){
	p_dlnode_t new_item;
	void *newp=NULL;

	if(queue==NULL){
		errno=EINVAL;
		return -1;
		}
	newp=malloc(n);
	if(!newp){
		errno=ENOMEM;
		return -1;
		}
	if(queue->size==0){
		memcpy(newp,pitem,n);
		queue->tail->pdata=newp;
		queue->size++;
		}
	else{
		new_item=(p_dlnode_t)malloc(sizeof(dlnode_t));
		if(new_item==NULL){
			free(newp);
			errno=ENOMEM;
			return -1;
			}
		memcpy(newp,pitem,n);
        		new_item->pdata=newp;
		new_item->next=NULL;
        		new_item->prev=queue->tail;
		queue->tail->next=new_item;
		queue->tail=queue->tail->next;
        		queue->size++;
    		}
	return 0;
	}

void* deque_get_head(p_deque_t queue){
	if(queue==NULL || queue->size==0){
		errno=EINVAL;
		return NULL;
		}
	else return queue->head->pdata;
	}
	
void* deque_get_tail(p_deque_t queue){
	if(queue==NULL || queue->size==0){
		errno=EINVAL;
		return NULL;
		}
	else return queue->tail->pdata;
	}

void deque_pop_head(p_deque_t queue){
	p_dlnode_t p;

	if(queue==NULL || queue->size==0){
		errno=EINVAL;
		return ;
		}
	p=queue->head;
	queue->head=queue->head->next;
	free(p->pdata);
	free(p);
	queue->size--;
	}

void deque_pop_tail(p_deque_t queue){
	p_dlnode_t p;

	if(queue==NULL || queue->size==0){
		errno=EINVAL;
		return ;
		}
	p=queue->tail;
	queue->tail=queue->tail->prev;
	free(p->pdata);
	free(p);
	queue->size--;
	}

void deque_destroy(p_deque_t queue){
	int count;

	if(queue==NULL){
		errno=EINVAL;
		return ;
		}
	for(count=queue->size;count>=1;count--){
		deque_pop_head(queue);
		if(errno==EINVAL)
			break;
		}
	free(queue);
	}

