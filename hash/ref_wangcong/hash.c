#include "hash.h"

int hash(void* key,size_t n,int hashsize){/*Hmmm,I like this way.*/
	unsigned int val=0;
	size_t i=n;
	if(hashsize<=1){
		errno=EINVAL;
		return -1;
		}
	while(i--)
		val+=*(char*)key++;
	return val%hashsize;
	}

p_hstable_t hashtable_create(int tablesize){/*You had better choose a prime number as the 'tablesize'*/
	p_hstable_t hstable;
	int i;

	if(tablesize<=0){
		errno=EINVAL;
		return NULL;
		}
	hstable=(p_hstable_t)malloc(sizeof(hstable_t));
	if(hstable==NULL){
		errno=ENOMEM;
		return NULL;
		}
	hstable->size=tablesize;
	hstable->table=(p_hsnode_t)malloc(tablesize*sizeof(hsnode_t));
	if(hstable->table==NULL){
		free(hstable);
		errno=ENOMEM;
		return NULL;
		}
	for(i=0;i<tablesize;i++){
		hstable->table[i].len=0;/*Notice this!Yeah,it is '.' not '->'*/
		hstable->table[i].next=NULL;
		}
	return hstable;
	}
	
int hash_insert(p_hstable_t hstable,void* pitem,size_t n){
	int position;
	p_slnode_t new_item;
	void *newp=NULL;

	if((position=hash(pitem,n,hstable->size))==-1)return -1;
	new_item=(p_slnode_t)malloc(sizeof(slnode_t));
	if(new_item==NULL){
		errno=ENOMEM;
		return -1;
		}
	newp=malloc(n);
	if(!newp){
		free(new_item);
		errno=ENOMEM;
		return -1;
		}
	memcpy(newp,pitem,n);
	new_item->pdata=newp;
	new_item->next=hstable->table[position].next;
	hstable->table[position].next=new_item;
	hstable->table[position].len++;
	return 0;
	}

p_slnode_t hash_find(p_hstable_t hstable,void* pitem,size_t n,int (*comp)(void*,void*)){/*Returning NULL doesn't only mean errors occures,but also means not found.Take care!*/
	int position;
	p_slnode_t current;

	if(hstable==NULL){
		errno=EINVAL;
		return NULL;
		}
	if((position=hash(pitem,n,hstable->size))==-1)return NULL;
	current=hstable->table[position].next;
	while(current->next!=NULL && comp(current->pdata,pitem)!=0)
		current=current->next;
	if(current->next==NULL && comp(current->pdata,pitem)!=0)/*The last one*/
		return NULL;
	else return current;
	}

void hashtable_clear(p_hstable_t hstable){
	register int i;
	p_slnode_t here,p;
	
	if(hstable==NULL){
		errno=EINVAL;
		return;
		}
	for(i=0;i<hstable->size;i++){
		p=here=hstable->table[i].next;
		while(here!=NULL){
			here=here->next;
			if(here==NULL){
				free(p->pdata);
				free(p);
				break;
				}
			p->next=here->next;
			free(here->pdata);
			free(here);
			here=p;
			}
		hstable->table[i].next=NULL;
		hstable->table[i].len=0;
		}
	}
	
void hashtable_destroy(p_hstable_t hstable){
	if(hstable==NULL){
		errno=EINVAL;
		return;
		}
	hashtable_clear(hstable);
	free(hstable->table);
	free(hstable);
	}

/***************************************************************************************/

p_hstable2_t hashtable_create2(int tablesize){/*You had better choose a prime number as the 'tablesize'.And it should be large enough!*/
	p_hstable2_t hstable;
	int i;

	hstable=(p_hstable2_t)malloc(sizeof(hstable2_t));
	if(hstable==NULL){
		errno=ENOMEM;
		return NULL;
		}
	hstable->size=tablesize;
	hstable->table=(p_hsnode2_t)malloc(tablesize*sizeof(hsnode2_t));
	if(hstable->table==NULL){
		free(hstable);
		errno=ENOMEM;
		return NULL;
		}
	for(i=0;i<tablesize;i++)
		hstable->table[i].atr=empty;
	return hstable;
	}
	
int hash_insert2(p_hstable2_t hstable,void* pitem,size_t n){
	register int position,offset=0;
	void *newp=NULL;
	
	if(hstable==NULL){
		errno=EINVAL;
		return -1;
		}
	newp=malloc(n);
	if(!newp){
		errno=ENOMEM;
		return -1;
		}
	if((position=hash(pitem,n,hstable->size))==-1)return -1;
	while(hstable->table[position].atr==full){
		offset=2*offset+1;
		position=(position+offset) % hstable->size;
		}
	memcpy(newp,pitem,n);
	hstable->table[position].pdata=newp;
	hstable->table[position].atr=full;
	return 0;
	}
	
p_hsnode2_t hash_find2(p_hstable2_t hstable,void* pitem,size_t n,int (*comp)(void*,void*)){
	register int position,offset=0;
	p_hsnode2_t here;

	if(hstable==NULL){
		errno=EINVAL;
		return NULL;
		}
	position=hash(pitem,n,hstable->size);
	while(hstable->table[position].atr==full && comp(hstable->table[position].pdata,pitem)!=0){
		offset=(2*offset+1);
		position=(position+offset) % hstable->size;
		}
	if(hstable->table[position].atr==empty)return NULL;
	here=&(hstable->table[position]);
	return here;
	}

void hashtable_clear2(p_hstable2_t hstable){
	register int i;

	if(hstable==NULL){
		errno=EINVAL;
		return;
		}
	for(i=0;i<hstable->size;i++){
		hstable->table[i].atr=empty;
		free(hstable->table[i].pdata);
		}
	}

void hashtable_destroy2(p_hstable2_t hstable){
	if(hstable==NULL){
		errno=EINVAL;
		return;
		}
	free(hstable->table);
	free(hstable);
	}
