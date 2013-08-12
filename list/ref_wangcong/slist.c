#include "slist.h"

p_slist_t slist_create(void){
	p_slist_t list;
	list=(p_slist_t)malloc(sizeof(slist_t));
	if(list==NULL){
		errno=ENOMEM;
		return NULL;
		}
	list->size=0;
	list->head=(p_slnode_t)malloc(sizeof(slnode_t));
	if(list->head==NULL){
		free(list);
		errno=ENOMEM;
		return NULL;
		}
	list->head->pdata=NULL;
	list->head->next=NULL;	
	list->tail=list->head;
	return list;
	}
/*On success,return 0;else return -1.Er,I use a clever way to add a new item before the head,just set the argument 'number' 0 when the size isn't 0*/
int slist_insert(p_slist_t list,int number,void* pnew_item,size_t n){
	p_slnode_t current,new_node;
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
		if(number>0 && number<=list->size){
			new_node=(p_slnode_t)malloc(sizeof(slnode_t));
			if(new_node==NULL){
				errno=ENOMEM;
				return -1;
				}
			current=list->head;
			memcpy(new_pdata,pnew_item,n);
			new_node->pdata=new_pdata;/*points to the new-allocated mem*/

			while(count!=number-1){
				count++;
				current=current->next;
				}
			if(current->next==NULL)
				list->tail=new_node;
			new_node->next=current->next;
			current->next=new_node;
			list->size++;
		}else if(number==0){
			new_node=(p_slnode_t)malloc(sizeof(slnode_t));
			if(new_node==NULL){
				free(new_pdata);
				errno=ENOMEM;
				return -1;
				}
			memcpy(new_pdata,pnew_item,n);
			new_node->pdata=new_pdata;/*points to the new-allocated mem*/
			new_node->next=list->head;
			list->head=new_node;
			list->size++;
		}else{
			free(new_pdata);
			errno=EINVAL;
			return -1;
			}
	}else if(list->size==0 && number==0){
		memcpy(new_pdata,pnew_item,n);
		list->head->pdata=new_pdata;
		list->tail=list->head;
		list->size++;
	}else{
		free(new_pdata);
		errno=EINVAL;
		return -1;
		}
	return 0;
	}

void slist_destroy(p_slist_t list){/*Notice that on errors errno is set properly although it is void.To detect errors,use the  function perror().*/
	register int count;
	p_slnode_t current,ptr;

	if(list==NULL){
		errno=EINVAL;
		return;
		}
	ptr=current=list->head;
	for(count=1;count<=list->size;count++){
		current=current->next;
		free(ptr->pdata);
		free(ptr);
		ptr=current;
		}
	free(list);
	}
	
void slist_delete(p_slist_t list,int num){/*Notice that on errors errno is set properly although it is void.To detect errors,use the  function perror().*/
	int count=1;
	p_slnode_t temp,current;
	if(list==NULL || num<=0 || num>list->size){
		errno=EINVAL;
		return;
		}
	current=list->head;

	if(num==1){
		temp=current;
		list->head=current->next;
		list->size--;
		}
	else{
		while(count!=num-1){
			current=current->next;
			count++;
			}
		temp=current->next;
		if(temp->next==NULL)list->tail=current;
		current->next=temp->next;
		free(temp->pdata);
		free(temp);
		list->size--;
		}
	}
	
void slist_update(p_slist_t list,int num,void* pnew_item,size_t n){/*Notice that on errors errno is set properly although it is void.To detect errors,use the  function perror().*/
	p_slnode_t current;
	int count=1;

	if(list==NULL || num<=0 || num>list->size){
		errno=EINVAL;
		return;
		}
	current=list->head;
	while(count!=num){
		current=current->next;
		count++;
		}
	memcpy(current->pdata,pnew_item,n);
	}

int slist_search(p_slist_t list,void* pitem,int (*comp)(void*,void*)){/*On success,returns the position of the item you want if it is in the list or returns 0 if there is no such item in the list.On errors, -1 is returned and errno is properly set.*/
/**Yeah,as you see,the last argument is a pointer that points to a function which is defined by you to compare the items you need.**/
	register p_slnode_t current;
	int count=1;
	if(list==NULL){
		errno=EINVAL;
		return -1;
		}
	current=list->head;
	while(comp(current->pdata,pitem)!=0 && current->next!=NULL){
		current=current->next;
		count++;
		}
	if(current->next==NULL && comp(current->pdata,pitem)!=0)return 0;
	return count;
	}

void* slist_visit(p_slist_t list,int num){
	register int count;
	p_slnode_t current=list->head;

	if(list==NULL || num<=0 || num>list->size){
		errno=EINVAL;
		return NULL;
		}
	for(count=1;count<num;count++)
		current=current->next;
	return current->pdata;
	}

void slist_trav(p_slist_t list,void(*func)(void*)){
	int i;
	if(list==NULL || list->size==0){
		errno=EINVAL;
		return ;
		}
	for(i=1;i<=list->size;i++)
		(*func)(slist_visit(list,i));
	return ;
	}
