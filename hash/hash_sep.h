#ifndef GUARD_HASH_SEP_H
#define GUARD_HASH_SEP_H
typedef int ElemType;
typedef struct _ListNode
{
	ElemType Element;
	struct _ListNode *Next;
}ListNode;
typedef ListNode *Position;
typedef ListNode *List;

typedef struct _HashTbl
{
	int TableSize;
	List *TheLists;
}HashTable;
typedef HashTable *ptrHashTable;



ptrHashTable InitializeTable(int TableSize);
void DestroyTable(ptrHashTable H);
Position Find(ElemType key, ptrHashTable H);
Position FindPrevious(ElemType key, ptrHashTable H);  //for delete element from HashTable
void Insert(ElemType key, ptrHashTable H);
ElemType Retrieve(Position P);
void Delete(ptrHashTable H, ElemType e);
//ptrHashTable MakeEmpty(ptrHashTable H);
unsigned int Hash(int key, int TableSize);
unsigned int Hash2(const char *key, int TableSize);
unsigned int Hash3(const char *key, int TableSize);
void PrintList(List L);

#endif