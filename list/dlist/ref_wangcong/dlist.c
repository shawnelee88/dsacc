#include "dlist.h"

p_dlist_t dlist_create(void){
	p_dlist_t list;

	if((list=(p_dlist_t)malloc(sizeof(dlist_t)))==NULL){
		errno=ENOMEM;
		return NULL;
		}
	list->size=0;
	list->head=(p_dlnode_t)malloc(sizeof(dlnode_t));
	if(list->head==NULL){
		free(list);
		errno=ENOMEM;
		return NULL;
		}
	list->head->pdata=NULL;
	list->head->next=list->head->prev=NULL;
	list->tail=list->head;
	return list;
	}

int dlist_add_after(p_dlist_t list,int number,void* pnew_item,size_t n){
	p_dlnode_t current,new_node;
	void *new_pdata=NULL;
	int count=0;

	if(list==NULL){
		errno=EINVAL;
		return -1;
		}
	new_pdata=malloc(n);
	if(!new_pdata){
		errno=ENOMEM;
		return -1;
		}
	if(list->size!=0){
		new_node=(p_dlnode_t)malloc(sizeof(dlnode_t));
		if(new_node==NULL){
			free(new_pdata);
			errno=ENOMEM;
			return -1;
			}
		memcpy(new_pdata,pnew_item,n);
		new_node->pdata=new_pdata;/*This must point to new mem!*/
		new_node->next=new_node->prev=NULL;
		if(number>0 && number<=list->size){
			current=list->head;
			while(count!=number-1){
				count++;
				current=current->next;
        			}
            			if(current->next==NULL){
                			current->next=new_node;
                			new_node->prev=current;
                			list->tail=list->tail->next;
                			list->size++;
            				return 0;
    				}
            			new_node->prev=current;
            			new_node->next=current->next;
            			current->next->prev=new_node;
            			current->next=new_node;
            			list->size++;
        		}else{
            			free(new_node);
            			free(new_pdata);
			errno=EINVAL;
            			return -1;
    	       		}
	}else{
		if(number!=0){
			free(new_pdata);
			errno=EINVAL;
			return -1;
			}
		memcpy(new_pdata,pnew_item,n);
        	list->head->pdata=new_pdata;
       		list->size++;		
		}
	return 0;
	}

int dlist_add_before(p_dlist_t list,int number,void* pnew_item,size_t n){
	p_dlnode_t current,new_node;
	void *new_pdata=NULL;
    	int count=1;
   
    	if(list==NULL) {
    		errno=EINVAL;
    		return -1;
    		}
    	new_pdata=malloc(n);
	if(!new_pdata){
		errno=ENOMEM;
		return -1;
		}
    	if(list->size!=0){
            		new_node=(p_dlnode_t)malloc(sizeof(dlnode_t));
            		if(new_node==NULL){
            			free(new_pdata);
			errno=ENOMEM;
			return -1;
			}
		memcpy(new_pdata,pnew_item,n);
            		new_node->pdata=new_pdata;
            		new_node->prev=new_node->next=NULL;
        		if(number>0 && number<=list->size){
            			current=list->head;
            			while(count<number){
            				count++;
                			current=current->next;
        			}
            			if(count==1){
                			list->head->prev=new_node;
                			new_node->next=list->head;
                			list->head=list->head->prev;
				list->size++;
				return 0;
        			}
            			current->prev->next=new_node;
            			new_node->prev=current->prev;
            			current->prev=new_node;
            			new_node->next=current;
            			list->size++;
            		}else{
            			free(new_node);
            			free(new_pdata);
                		errno=EINVAL;
            			return -1;
        		}
	}else{
		if(number!=0){
			free(new_pdata);
			errno=EINVAL;
			return -1;
			}
		memcpy(new_pdata,pnew_item,n);
		list->head->pdata=new_pdata;
		list->size++;
		}
	return 0;
	}

void dlist_destroy(p_dlist_t list){
	int count;
	p_dlnode_t current,ptr;

	if(list==NULL){
		errno=EINVAL;
		return;
		}
	ptr=current=list->head;

	if(list->size!=0){
		for(count=1;count<=list->size;count++){
			current=current->next;
			free(ptr->pdata);
			free(ptr);
			ptr=current;
			}
		}
	free(list);
	}

void dlist_delete(p_dlist_t list,int num){
	p_dlnode_t temp,current;
	int count=1;

	if(list==NULL){
		errno=EINVAL;
		return;
		}
	current=list->head;
	while(count<num){
		count++;
		current=current->next;
		}
	if(count==1){
		temp=list->head;
		list->head=list->head->next;
		free(temp->pdata);
		free(temp);
		list->head->prev=NULL;
		list->size--;
		return;
		}
	if(count==list->size){
		temp=list->tail;
		list->tail=list->tail->prev;
		free(temp->pdata);
		free(temp);
		list->tail->next=NULL;
		list->size--;
		return;
		}
	temp=current;
	current->prev->next=current->next;
	current->next->prev=current->prev;
	free(temp->pdata);
	free(temp);
	list->size--;
	}

void dlist_update(p_dlist_t list,int num,void* pnew_item,size_t n){
	p_dlnode_t current;
    	int count=0;

    	if(num<=0 || num>list->size){
		errno=EINVAL;
		return;
		}
    	current=list->head;
    	while(count!=num-1){
        		current=current->next;
        		count++;
    		}
    	memcpy(current->pdata,pnew_item,n);
    	}

void* dlist_visit(p_dlist_t list,int num){
    	int count;
    	p_dlnode_t current;

    	if(list==NULL || num<=0 || num>list->size){
		errno=EINVAL;
		return NULL;
		}
	current=list->head;
    	for(count=1;count<num;count++)
        		current=current->next;
    	return current->pdata;
    	}
/*only can find the first item,if there are more than one*/
int dlist_search(p_dlist_t list,void* pitem,int (*comp)(void*,void*)){
	p_dlnode_t current=list->head;
	int count=1;

	while(comp(current->pdata,pitem)!=0 && current->next!=NULL){
		current=current->next;
		count++;
		}
	if(current->next==NULL && comp(current->pdata,pitem)!=0)
		return 0;
	return count;
	}
	
void dlist_trav(p_dlist_t list,void(*func)(void*)){
	int i;
	p_dlnode_t current;
	
	if(list==NULL || list->size==0){
		errno=EINVAL;
		return ;
		}
	current=list->head;
	for(i=1;i<=list->size;current=current->next,i++)
		(*func)(current->pdata);
	return ;
	}

