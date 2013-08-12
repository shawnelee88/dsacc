#include <stdlib.h>
#include <stdio.h>
#include "avl_tree.h"
#include "fatal.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

AvlTree MakeEmpty( AvlTree T )
{
	if(T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

//recursion edition
Position Find(ElemType x, AvlTree T)
{
	if(T == NULL){
		return NULL;
	}

	if(x < T->Element){
		return Find(x, T->Left);
	}else if(x > T->Element){
		return Find(x, T->Right);
	}else{
		return T;
	}
}

//loop edition
Position Find2(ElemType x, AvlTree T)
{
	AvlTree Temp = T;
	while(Temp){
		if(Temp->Element > x){
			Temp = Temp->Left;
		}else if(Temp->Element < x){
			Temp = Temp->Right;
		}else{
			break;
		}
	}
	return Temp;
}

//recursion edition
Position FindMin(AvlTree T)
{
	if(T == NULL){
		return NULL;
	}else if(T->Left == NULL){
		return T;
	}else{
		return FindMin(T->Left);
	}
}

//loop edition
Position FindMin2(AvlTree T)
{
	AvlTree Temp = T;
	while(Temp->Left){
		Temp = Temp->Left;
	}
	return Temp;
}

//recursion edition
Position FindMax(AvlTree T)
{
	if(T == NULL){
		return NULL;
	}else if(T->Right == NULL){
		return T;
	}else{
		return FindMax(T->Right);
	}
}

//loop edition
Position FindMax2(AvlTree T)
{
	AvlTree Temp = T;
	while(Temp->Right){
		Temp = Temp->Right;
	}
	return Temp;
}


//because of Parent in struct, must introduce "Pre" to point to 
//the parent of "T"
AvlTree Insert(ElemType x, AvlTree T, AvlTree Pre)
{
	if(T == NULL){
		T = malloc(sizeof(AvlNode));
		if(T == NULL){
			FatalError("Out of space!");
		}else{
			T->Element = x;
			T->Height = 0;
			T->bf = 0;
			T->Left = NULL;
			T->Right = NULL;
			T->Parent = Pre;
		}
	}else if(x < T->Element){
		T->Left = Insert(x, T->Left, T);
		//if(T->bf == 2){
		if(Height(T->Left) - Height(T->Right) == 2){
			if(x < T->Left->Element){    //LL
				T = SingleRotateWithLeft(T);
			}else{  //LR
				T = DoubleRotateWithLeft(T);
			}
		}
	}else if(x > T->Element){
		T->Right = Insert(x, T->Right, T);
		//if(T->bf == -2){
		if(Height(T->Left) - Height(T->Right) == -2){
			if(x > T->Right->Element){  //RR
				T = SingleRotateWithRight(T);
			}else{ //RL
				T = DoubleRotateWithRight(T);
			}
		}
	}
	/*else x is in the tree already, we will do nothing*/
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	T->bf = Height(T->Left) - Height(T->Right);

	return T;
}


//先按照一般的查找二叉树将节点删除后，再由该节点自下而上的回溯，调整每个节点到平衡至根节点
AvlTree Delete(ElemType x, AvlTree T)
{
	Position TmpCell;
	Position Target = T;
	Position Parent = NULL;
	Position Grand = NULL;
	ElemType ele;

	while(Target){  //deletion
		if(Target->Element < x){  //Go Right child
			Target = Target->Right;
		}else if(Target->Element > x){  //Go Left child
			Target = Target->Left;
		}else if(Target->Left && Target->Right){  //Found the element, has Two children
			TmpCell = FindMin(Target->Right);  //the minimal node has no left child,最小节点必然没有左子树
			Parent = TmpCell->Parent;
			Target->Element = TmpCell->Element;
			//判断被删除节点(FindMin返回的最小节点)是其父母的左（右）子树，分别处理；
			if(TmpCell->Parent->Element <= TmpCell->Element){  
				//右子树：注意若被删节点的父节点不是Target，则其不可能是最小节点，故被删节点的父节点肯定就是Target，
				//又由于Target->Element = TmpCell->Element,故父节点的值就等于被删节点的值，且只能取等号
				TmpCell->Parent->Right = TmpCell->Right;
				if(TmpCell->Right){
					TmpCell->Right->Parent = TmpCell->Parent;
				}
			}else{  //左子树
				TmpCell->Parent->Left = TmpCell->Right;
				if(TmpCell->Right){
					TmpCell->Right->Parent = TmpCell->Parent;
				}
			}

			free(TmpCell);
			break;
		}else{   //one child or zero child
			TmpCell = Target;
			Parent = TmpCell->Parent;
			if(Target->Left == NULL && Target->Right != NULL){  //right child
				if(Parent == NULL){
					Target->Right->Parent = NULL;
				}else{
					if(Parent->Element < x){  //判断删除节点位置在父母节点的左还是右
						Parent->Right = Target->Right;
						Target->Right->Parent = Target->Parent;
					}else if(Parent->Element > x){
						Parent->Left = Target->Right;
						Target->Right->Parent = Target->Parent;
					}
				}
			}else if(Target->Left == NULL && Target->Right == NULL){  //no child
				if(Parent == NULL){
					Target = NULL;
				}else{
					if(Parent->Element < x){
						Parent->Right = NULL;
					}else if(Parent->Element > x){
						Parent->Left = NULL;
					}
				}
			}else{  //(Target->Left != NULL & Target->Right == NULL), left child
				if(Parent == NULL){
					Target->Left->Parent = NULL;
				}else{
					if(Parent->Element < x){
						Parent->Right = Target->Left;
						Target->Left->Parent = Target->Parent;
					}else if(Parent->Element > x){
						Parent->Left = Target->Left;
						Target->Left->Parent = Target->Parent;
					}
				}
			}
			free(TmpCell);
			break;
		}
	}

	while(Parent){  //由删除节点往上调整平衡
		ele = Parent->Element;
		Parent->Height = max(Height(Parent->Left), Height(Parent->Right)) + 1;
		Parent->bf = Height(Parent->Left) - Height(Parent->Right);
		Grand = Parent->Parent;
		if(Parent->bf == -2){  //left subtree is lower than right subtree
			if(Parent->Right->bf > 0){
				Parent = DoubleRotateWithRight(Parent);
			}else{
				Parent = SingleRotateWithRight(Parent);
			}
		}else if(Parent->bf == 2){  //left subtree is higher than right subtree
			if(Parent->Left->bf < 0){
				Parent = DoubleRotateWithLeft(Parent);
			}else{
				Parent = SingleRotateWithLeft(Parent);
			}
		}
		
		//why no equal??????
		if(Grand){  //祖父母：这是必须的，否则无法连接,（个人意见这个if好像没什么用，下面else有用）
			//if(Grand->Element > ele){  //parent is grand's left tree
			//	Grand->Left = Parent;
			//}else{
			//	Grand->Right = Parent;
			//}
			//Parent->Parent = Grand;
		}else{  //parent is grand's right tree
			T = Parent;   //注意：此时说明已经到了根节点，需要变化
		}

		Parent = Parent->Parent;  //往上走
	}

	return T;
}


ElemType Retrieve(Position P)
{
	if(P == NULL){
		return -1;
	}else{
		return P->Element;
	}
}


void InOrderTraverse(AvlTree T)
{
	if(T != NULL){
		InOrderTraverse(T->Left);
		printf("%d    ", Retrieve(T));
		InOrderTraverse(T->Right);
	}
}



void PreOrderTraverse(AvlTree T)
{
	if(T != NULL){
		printf("%d    ", Retrieve(T));
		PreOrderTraverse(T->Left);
		PreOrderTraverse(T->Right);
	}
}


void PostOrderTraverse(AvlTree T)
{
	if(T != NULL){
		PostOrderTraverse(T->Left);
		PostOrderTraverse(T->Right);
		printf("%d    ", Retrieve(T));
	}
}

int Height(Position P)
{
	if(P == NULL){
		return -1;
	}else{
		return P->Height;
	}
}

//K2 has a left child, perform a rotate between K2 and its left child
//update heights, then return new root
Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	
	K1 = K2->Left;
	K2->Left = K1->Right;
	if(K1->Right){
		K1->Right->Parent = K2;
	}
	K1->Right = K2;
	K1->Parent = K2->Parent;
	K2->Parent = K1;
	
	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), K2->Height) + 1;
	K2->bf = Height(K2->Left) - Height(K2->Right);
	K1->bf = Height(K1->Left) - Height(K1->Right);

	return K1;
}


//K2 has a right child, perform a rotate between K2 and its right child
//update heights, then return new root
Position SingleRotateWithRight(Position K2)  
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	if(K1->Left){
		K1->Left->Parent = K2;
	}
	K1->Left = K2;
	K1->Parent = K2->Parent;
	K2->Parent = K1;

	K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = max(Height(K1->Left), K2->Height) + 1;
	K2->bf = Height(K2->Left) - Height(K2->Right);
	K1->bf = Height(K1->Left) - Height(K1->Right);

	return K1;
}


//K3 has a Left child and K3's Left child has a right child
//do the Left-Right double rotation
//update the heights, then return new root
Position DoubleRotateWithLeft(Position K3)
{	
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}


//K3 has a Right child and K3's Left child has a Left child
//do the Right-Left double rotation
//update the heights, then return new root
Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}