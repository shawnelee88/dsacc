#include "clist.h"

p_clist_t clist_create(void){
	p_clist_t list;

	list=(p_clist_t)malloc(sizeof(clist_t));
	if(list==NULL){
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
	list->tail=(p_dlnode_t)malloc(sizeof(dlnode_t));
	if(list->tail==NULL){
		free(list->head);
		free(list);/*Aha!I am careful enough!*/
		errno=ENOMEM;
		return NULL;
		}
	list->head->pdata=NULL;
	list->tail->pdata=NULL;
	list->head->prev=list->tail;
	list->tail->next=list->head;
	list->head->next=list->tail;
	list->tail->prev=list->head;
	return list;
	}
/*Just add **after** the node*/
int clist_insert(p_clist_t list,int num,void* pitem,size_t n){
	p_dlnode_t current,new_node;
	void *new_pdata=NULL;
	int count=0;

	if(list==NULL || num<0 || num>list->size){
		errno=EINVAL;
		return -1;
		}
	new_pdata=malloc(n);
	if(!new_pdata){
		errno=ENOMEM;
		return -1;
		}
	current=list->head;
	if(list->size>1){
		new_node=(p_dlnode_t)malloc(sizeof(dlnode_t));
		if(new_node==NULL){
			free(new_pdata);
			errno=ENOMEM;
			return -1;
			}
		memcpy(new_pdata,pitem,n);
		new_node->pdata=new_pdata;
		for(count=1;count<num;count++){
			current=current->next;
			}
		new_node->prev=current;/*We must be careful!*/
		new_node->next=current->next;
		current->next->prev=new_node;
		current->next=new_node;
		list->size++;
		if(current==list->tail){
			list->tail=list->tail->next;
			return 0;
			}
		}
	else{
		if(list->size==0 && num==0){
			memcpy(new_pdata,pitem,n);
			list->head->pdata=new_pdata;
			list->size++;
			}
		else if(list->size==1 && num==1){
			memcpy(new_pdata,pitem,n);
			list->tail->pdata=new_pdata;
			list->size++;
		}
		else{
			free(new_pdata);
			errno=EINVAL;
			return -1;
			}
		}
	return 0;
	}
	
void clist_delete(p_clist_t list,int num){
	p_dlnode_t temp,current;
	int count=1;

	if(list==NULL || list->size==0 || num<=0 || num>list->size){
		errno=EINVAL;
		return;
		}
	current=list->head;
	while(count<num){
		count++;
		current=current->next;
		}
	temp=current;
	if(count==1){
		list->head=list->head->next;
		if(list->size==2){
			free(list->head->pdata);
			list->head=list->head->next;
			list->size--;
			return;
			}
		if(list->size==1){
			free(list->head->pdata);/****************For Debug*******************/
			list->head=list->head->prev;
			list->size--;
			return;
			}
		}
	if(count==list->size){
		list->tail=list->tail->prev;
		if(list->size==2){
			free(list->tail->pdata);
			list->tail=list->tail->prev;
			list->size--;
			return;
			}
		if(list->size==1){
			free(list->tail->pdata);
			list->tail=list->tail->next;
			list->size--;
			return;
			}
		}
	current->prev->next=current->next;
	current->next->prev=current->prev;
	free(temp);
	list->size--;
	}
	
void clist_update(p_clist_t list,int num,void* pnew_item,size_t n){
	p_dlnode_t current;
	int count=0;

	if(list==NULL || list->size==0 || num<=0 || num>list->size){
		errno=EINVAL;
		return ;
		}
	current=list->head;
	while(count!=num-1){
		current=current->next;
		count++;
		}
	memcpy(current->pdata,pnew_item,n);
	}
	
void clist_destroy(p_clist_t list){
	int count;
	p_dlnode_t current,ptr;

	if(list==NULL){
		errno=EINVAL;
		return ;
		}
	ptr=current=list->head;
	for(count=1;count<list->size;count++){
		current=current->next;
		free(ptr->pdata);
		free(ptr);
		ptr=current;
		}
	free(ptr->pdata);
	free(ptr);
	free(list);
	}

void* clist_visit(p_clist_t list,int num){
	int count;
	p_dlnode_t current;

	current=list->head;
	if(list==NULL || list->size==0 || num<=0 || num>list->size ){
		errno=EINVAL;
		return NULL;
		}
	for(count=1;count<num;count++)
		current=current->next;
	return current->pdata;
	}
/*only can find the first item if it has more than one*/
int clist_search(p_clist_t list,void* pitem,int (*comp)(void*,void*)){
	p_dlnode_t current=list->head;
	int count=1;

	if(list==NULL){
		errno=EINVAL;
		return -1;
		}
	while(comp(current->pdata,pitem)!=0 && current->next!=list->head){
		current=current->next;
		count++;
                }
	if(current->next==list->head && comp(current->pdata,pitem)!=0){
		return 0;/*if none,return zero!*/
 		}
	return count;
	}
void clist_rotate(p_clist_t list,int num){
	int i;
	if(list==NULL || list->size==0){
		errno=EINVAL;
		return ;
		}

	if(num<0){
		i=-num;/*Er,we should NOT change the value of an argument.*/
		i=i%(list->size);/*op*/
		num=-i;
		while(num!=0){
			list->tail=list->tail->prev;
			list->head=list->head->prev;
			num++;
			}
		}
	else if(num>0){
		i=num;
		i=i%(list->size);/*op*/
		num=i;
		while(num!=0){
			list->head=list->head->next;
			list->tail=list->tail->next;
			num--;
			}
		}
	else{
		errno=EINVAL;
		return;
		}
	}
void clist_trav(p_clist_t list, void(*func)(void*)){
	int i;
	if(list==NULL || list->size==0){
		errno=EINVAL;
		return ;
		}
	for(i=1;i<=list->size;i++)
		(*func)(clist_visit(list,i));
	}

