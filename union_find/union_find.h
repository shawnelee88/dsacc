#ifndef GUARD_UNION_FIND_H
#define GUARD_UNION_FIND_H

#define NumSets 128

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElemType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
void SetUnion2(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElemType X, DisjSet S);
SetType Find2(ElemType X, DisjSet S);

#endif