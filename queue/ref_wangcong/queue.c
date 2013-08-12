#include "queue.h"

p_queue_t queue_create(void){
	p_queue_t queue;
	queue=(p_queue_t)malloc(sizeof(queue_t));
	if(queue==NULL){
		errno=ENOMEM;
		return NULL;
		}
	queue->head=(p_slnode_t)malloc(sizeof(slnode_t));
	if(queue->head==NULL){
		free(queue);
		errno=ENOMEM;
		return NULL;
		}
	queue->size=0;
	queue->head->pdata=NULL;
	queue->head->next=NULL;
	queue->tail=queue->head;
	return queue;
	}

int queue_isempty(p_queue_t queue){
	if(queue==NULL){
		errno=EINVAL;
		return -1;
		}
	return queue->size==0;
	}

int queue_put(p_queue_t queue,void* pitem,size_t n){
	p_slnode_t new_item;
	void* newp=NULL;

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
		new_item=(p_slnode_t)malloc(sizeof(slnode_t));
		if(new_item==NULL){
			free(newp);
			errno=ENOMEM;
			return -1;
			}
		memcpy(newp,pitem,n);
        		new_item->pdata=newp;
        		new_item->next=NULL;
        		queue->tail->next=new_item;
        		queue->tail=queue->tail->next;
        		queue->size++;
    		}
	return 0;
	}

void* queue_get(p_queue_t queue){
	if(queue==NULL || queue->size==0){/*Notice here! If a is false, when computes a||b, the compiler won't compute expression b.*/
		errno=EINVAL;
		return NULL;
		}
	return queue->head->pdata;
	}

void queue_delete(p_queue_t queue){
	p_slnode_t p;

	if(queue==NULL){
		errno=EINVAL;
		return;
		}
	p=queue->head;
	queue->head=queue->head->next;
	free(p->pdata);
	free(p);
	queue->size--;
	}

void queue_destroy(p_queue_t queue){
	register int count;
    
	if(queue==NULL){
		errno=EINVAL;
		return;
		}
	for(count=queue->size;count>=1;count--)
		queue_delete(queue);
	free(queue);
	}

