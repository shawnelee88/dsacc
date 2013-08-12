/*assume header node use*/
#include <stdio.h>
#include "dlist.h"
#include "fatal.h"




/*initialize an empty list*/
DList MakeEmpty(DList L)
{
	if(L != NULL)
		DeleteList(L);

	L = malloc(sizeof(struct _DList));
	if(L == NULL)
	{
		FatalError("Out of Memory!");
	}
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;

	return L;
}



/*return true if L is empty*/
int IsEmpty(DList L)
{
	return L->size == 0;
}





/*return Position of e in L, NULL if not found*/
PtrToNode Find(DList L, ElemType e)
{
	PtrToNode P;

	P = L->head;
	while((P != NULL) && (P->data != e))
	{
		P= P->next;
	}
	return P;
}


/*delete first occurrence of e from list L*/
int Delete(DList L, ElemType e)
{
	PtrToNode pNode;

	pNode = Find(L, e);
	if(pNode == NULL)
	{
		printf("Not found!");
		return -1;
	}

	if (pNode->prev == NULL) //remove from head of dlist
	{
		 
		if (pNode->next == NULL)  //remove the only one node
		{
			L->head = NULL; 
			L->tail = NULL; 
		}
		else  //more than one node
		{
			L->head = pNode->next; 
			pNode->next->prev = NULL; 
		}
	}
	else  //not from head of dlist
	{		  
		if (pNode->next == NULL)  //tail of dlist
		{
			pNode->prev->next = NULL;
			L->tail = pNode->prev;           
		}
		else
		{
			pNode->prev->next = pNode->next;
			pNode->next->prev = pNode->prev; 
		}
	}
	
	free(pNode);
	(L->size)--;
	return 0;
}



/*Insert after legal Position P
* Header implementation assumed
* Parameter L is unused 
**/
void Insert(DList L, ElemType e, PtrToNode P)
{
	PtrToNode pNewNode;
	PtrToNode pTmpNode;

	

	pNewNode = (PtrToNode)malloc(sizeof(Node));
	if(pNewNode == NULL)
	{
		FatalError("Out of space");
	}	
	pNewNode->data = e;
	pNewNode->prev = NULL;
	pNewNode->next = NULL;


	if(P == NULL) 
	{
		pTmpNode = L->head;
		if(pTmpNode == NULL)  //empty list
		{
			L->head = pNewNode;
			L->tail = pNewNode;
			pNewNode->prev = NULL;
			pNewNode->next = NULL;
		}
		else  //insert before first node
		{
			L->head = pNewNode;
			pTmpNode->prev = pNewNode;
			pNewNode->prev = NULL;
			pNewNode->next = pTmpNode;
		}
	}
	else  
	{
		pTmpNode = P->next;
		P->next = pNewNode;		
		if(pTmpNode == NULL)  //tail of dlist
		{
			pNewNode->prev = P;
			L->tail = pNewNode;
		}
		else  //not tail of dlist
		{
			pTmpNode->prev = pNewNode;
			pNewNode->prev = P;
			pNewNode->next = pTmpNode;
		}
	}

	(L->size)++;
}


/*delete list*/
void DeleteList(DList L)
{
	PtrToNode P, tmp;

	P = L->head;
	free(L);
	while(P != NULL){
		tmp = P->next;
		free(P);
		P = tmp;
	}
	
}


PtrToNode Advance(PtrToNode P)
{
	return P->next;
}

ElemType Retrieve(PtrToNode P)
{
	return P->data;
}


void PrintList(DList L)
{
	if(L->size == 0)
	{
		printf("Empty list!\n");
	}
	else
	{
		PtrToNode P = L->head;
		do{	
			printf("%d    ", Retrieve(P));
			P = Advance(P);
		}while(P != NULL);
		printf("\n");
	}		
}
