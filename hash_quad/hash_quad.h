#ifndef GUARD_HASH_QUAD_H
#define GUARD_HASH_QUAD_H
typedef unsigned int Index;
typedef Index Position;
typedef int ElemType;
enum KindOfEntry{Legitimate, Empty, Deleted};

typedef struct _HashEntry
{
	ElemType Element;
	enum KindOfEntry Info;
}HashEntry;
typedef HashEntry Cell;

typedef struct _HashTbl
{
	int TableSize;
	Cell *TheCells;
}HashTable;
typedef HashTable *ptrHashTable;

unsigned int Hash(int key, int TableSize);
ptrHashTable InitializeTable(int TableSize);
void DestroyTable(ptrHashTable H);
Position Find(ElemType key, ptrHashTable H);
void Insert(ElemType key, ptrHashTable H);
ElemType Retrieve(Position P, ptrHashTable H);
ptrHashTable Rehash(ptrHashTable H);
void Delete(ptrHashTable H, ElemType key);

#endif