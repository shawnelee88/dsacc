SplayTree MakeEmpty( SplayTree T )
{
	if( T != NULL )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	return NULL;	
}



SplayTree Find( ElementType X, SplayTree T )
{
	
}


SplayTree FindMin( SplayTree T )
{

}


SplayTree FindMax( SplayTree T )
{

}
SplayTree Initialize( void )
{

}


SplayTree Insert( ElementType X, SplayTree T )
{

}


SplayTree Remove( ElementType X, SplayTree T )
{

}


ElementType Retrieve( SplayTree T )
{
	return T->Element;
}


SplayTree Splay( ElementType Item, Position X )
{
	SplayNode Header;
	Position LeftTreeMax, RightTreeMin;

	Header.Left = Header.Right = Null;
	LeftTreeMax = RightTreeMin = &Header;
	NullNode->Element = Item;

	while( Item != X->Element )
	{
		if( Item < X->Element )
		{
			if( Item < X->Left->Element )
				X = SingleRotateWithLeft( X );
			if( X->Left == NullNode )
				break;
			/* Link right */
			RightTreeMin->Left = X;
			RightTreeMin = X;
			X = X->Left;
		}
		else
		{
			if( Item > X->Right->Element )
				X = SingleRotateWithRight( X );
			if( X->Right == NullNode )
				break;
			/* Link left */
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}  /* while Item != X->Element */

	/* Reassemble */
	LeftTreeMax->Right = X->Left;
	RightTreeMin->Left = X->Right;
	X->Left = Header.Right;
	X->Right = Header.Left;

	return X;
}

void InOrderTraverse(SplayTree T)
{
	if(T != NULL){
		InOrderTraverse(T->Left);
		printf("%d    ", Retrieve(T));
		InOrderTraverse(T->Right);
	}
}

void PreOrderTraverse(SplayTree T)
{
	if(T != NULL){
		printf("%d    ", Retrieve(T));
		PreOrderTraverse(T->Left);
		PreOrderTraverse(T->Right);
	}
}


void PostOrderTraverse(SplayTree T)
{
	if(T != NULL){
		PostOrderTraverse(T->Left);
		PostOrderTraverse(T->Right);
		printf("%d    ", Retrieve(T));
	}
}



SingleRotateWithLeft( Position K2 )
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	return K1;  /* New root */
}


Position SingleRotateWithRight(Position K2)
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	return K1;
}


Position DoubleRotateWithLeft(Position K3)
{

}


Position DoubleRotateWithRight(Position K3)
{

}