#include <stdio.h>
#include "07_polynomial.h"

int main()
{
	poly_t * p1 = NULL;
	poly_t * p2 = NULL;
	poly_t * p3 = NULL;

	p1 = insert(p1, 3, 12);
	p1 = insert(p1, 5, 9);
	p1 = insert(p1, 8, 7);
	p1 = insert(p1, 2, 6);
	p1 = insert(p1, 1, 6);
	p1 = insert(p1, 5, 3);
	printf("p1 = ");
	print_poly(p1);

	p2 = insert(p2, 2, 8);
	p2 = insert(p2, 1, 7);
	p2 = insert(p2, 5, 6);
	p2 = insert(p2, 4, 4);
	p2 = insert(p2, 7, 2);
	p2 = insert(p2, 9, 1);
	p2 = insert(p2, 25, 0);
	printf("p2 = ");
	print_poly(p2);

	p3 = add(p1, p2);
	printf("p3 = ");
	print_poly(p3);
	

	p1 = delete_poly(p1);
	p2 = delete_poly(p2);
	p3 = delete_poly(p3);
	printf("p1 = ");
	print_poly(p1);
	printf("p2 = ");
	print_poly(p2);
	printf("p3 = ");
	print_poly(p3);

	return 0;
}

