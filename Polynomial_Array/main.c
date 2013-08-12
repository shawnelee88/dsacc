#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main()
{
	Polynomial Poly1, Poly2, PolySum, PolyProd;
	ZeroPolynomial(Poly1);
	ZeroPolynomial(Poly2);
	Poly1->CoeffArray[0] = 1;
	Poly1->CoeffArray[14] = 5;
	Poly1->CoeffArray[1000] = 10;
	Poly2->CoeffArray[0] = 5;
	Poly2->CoeffArray[1] = 11;
	Poly2->CoeffArray[1492] = -2;
	Poly2->CoeffArray[1990] = 3;
	AddPolynomial(Poly1, Poly2, PolySum);
	MultPolynomial(Poly1, Poly2, PolyProd);

}