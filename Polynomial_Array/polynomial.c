#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

void ZeroPolynomial(Polynomial Poly)
{
	int i;

	for(i = 0; i <= MAXDEGREE; i++)
	{
		Poly->CoeffArray[i] = 0;
	}
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	int i;

	ZeroPolynomial(PolySum);
	PolySum->HighPower = max(Poly1->HighPower, Poly2->HighPower);
	for(i = 0; i <= MAXDEGREE; i++)
	{
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
	}
}


void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	int i, j;

	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if(PolyProd->HighPower > MAXDEGREE)
	{
		printf("Exceeded array size.");
		exit(1);
	}
	else
	{
		for(i = 0; i <= Poly1->HighPower; i++)
		{
			for(j = 0; j <= Poly2->HighPower; j++)
			{
				PolyProd->CoeffArray[i+j] += (Poly1->CoeffArray[i]) * (Poly2->CoeffArray[j]);
			}
		}
	}
}