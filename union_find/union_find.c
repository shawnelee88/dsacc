#include "fatal.h"
#include "union_find.h"

void Initialize(DisjSet S)
{
	int i;

	for(i = NumSets; i > 0; i--){
		S[i] = 0;
	}
}

/*assume Root1 and Root2 are roots*/
/*not the best method*/
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	S[Root2] = Root1;
}



/*union by height*/
void SetUnion2(DisjSet S, SetType Root1, SetType Root2)
{
	if(S[Root2] < S[Root1]){  //Root2 is deeper set
		S[Root1] = Root2;	//make Root2 the new root
	}else{
		if(S[Root1] == S[Root2]){   //same height
			S[Root1]--;    //update height
		}
		S[Root2] = Root1;   //make Root1 the new root
	}
}

//like find the root of X, recursive
SetType Find(ElemType X, DisjSet S)
{
	if(S[X] <= 0){
		return X;
	}else{
		return Find(S[X], S);
	}
}

//path compression, recursive, make root be the parent of every node accessed 
SetType Find2(ElemType X, DisjSet S)
{
	if(S[X] <= 0){
		return X;
	}else{
		return S[X] = Find2(S[X], S);
	}
}


//like find the root of X, not recursive
SetType Find3(ElemType X, DisjSet S)
{
	
}

//path compression, not recursive
SetType Find4(ElemType X, DisjSet S)
{
	ElemType root, trail, lead;

	for(root = X; S[root] > 0; root= S[root]){}  //find the root

	for(trail = X; trail != X; trail = lead){
		lead = S[trail];
		S[trail] = root;
	}
	return root;
}