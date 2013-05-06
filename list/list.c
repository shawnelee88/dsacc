/*assume header node use*/
#include <stdio.h>
#include "list.h"
#include "fatal.h"




/*initialize an empty list*/
List MakeEmpty(List L)
{
	if(L != NULL)
		DeleteList(L);
	
	L = malloc(sizeof(Node));
	if(L == NULL){
		FatalError("Out of Memory!");
	}
	L->next = NULL;

	return L;
}



/*return true if L is empty*/
int IsEmpty(List L)
{
    return L->next == NULL;
}



/*return true if P is the last position in List L
List L is unused in this implementation*/
int IsLast(Position P, List L)
{
    return P->next == NULL;
}


/*return Position of e in L, NULL if not found*/
Position Find(List L, ElemType e)
{
    Position P;
    
    P = L->next;
    while((P != NULL) && (P->data != e)){
        P= P->next;
    }
    return P;
}

Position Find2(List L, ElemType e)
{
    Position P;
    
    P = L;
    while((P->next != NULL) && (P->next->data != e)){
        P = P->next;
    }
    return P->next;
}


Position Find3(List L, ElemType e)
{
    Position P;
    int i;
    
    for(P=L->next; (P != NULL) && (P->data != e); P=P->next){}
    return P->next;
}


/*delete first occurrence of e from list L*/
void Delete(List L, ElemType e)
{
    Position P, tmp;
    
    P = FindPrevious(L, e);
    if(!IsLast(P, L)){  //e is found, delete it
        tmp = P->next;
		P->next = tmp->next;
        free(tmp);       
    }
}


/*if e is not found, return last node*/
Position FindPrevious(List L, ElemType e)
{
    Position P;
    
    P = L;
    while((P->next != NULL) && (P->next->data != e)){
        P = P->next;
    }
    return P;
}


/*Insert after legal Position P
* Header implementation assumed
* Parameter L is unused 
**/
void Insert(List L, ElemType e, Position P)
{
	Position tmp;
	
	tmp = (Position)malloc(sizeof(Node));
	if(tmp == NULL){
		FatalError("Out of space");
	}	
	tmp->data = e;
	tmp->next = P->next;
	P->next = tmp;
}


/*delete list*/
void DeleteList(List L)
{
	Position P, tmp;
	
	P = L->next;
	L->next = NULL;
	while(P != NULL){
		tmp = P->next;
		free(P);
		P = tmp;
	}
}


Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->next;
}

Position Advance(Position P)
{
	return P->next;
}

ElemType Retrieve(Position P)
{
	return P->data;
}


void PrintList(List L)
{
	Position P = Header(L);
	
	if(IsEmpty(L)){
		printf("Empty list!\n");
	}else{
		do{
			P = Advance(P);	
			printf("%d", Retrieve(P));
		}while(!IsLast(P, L));
		printf("\n");
	}
}
