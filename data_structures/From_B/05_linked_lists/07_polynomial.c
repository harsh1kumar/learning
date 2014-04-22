#include "07_polynomial.h"

#include <stdio.h>
#include <stdlib.h>

poly_t * insert(poly_t * p, int coff, int exp)
{
	poly_t * new_node;
	poly_t * node;

	new_node = (poly_t *) malloc( sizeof(poly_t) );
	if ( new_node == NULL )
	{
		fprintf(stderr, "Error: Memory allocation failed while inserting %dx%d", coff, exp);
		return NULL;
	}

	
	new_node->coff = coff;
	new_node->exp = exp;
	
	if (p == NULL)
	{
		new_node->next = NULL;
		return new_node;
	}

	for(node = p ; node->next != NULL; node = node->next)
	{
		if (node->next->exp < exp)
			break;
		else if (node->next->exp == exp)
		{
			node->next->coff += coff;
			free(new_node);
			return p;
		}
	}

	new_node->next = node->next;
	node->next = new_node;
	return p;
}

void print_poly(poly_t * p)
{
	for( ; p != NULL; p = p->next)
		printf("%dx%d ", p->coff, p->exp);
	printf("\n");
}

poly_t * delete_poly(poly_t * p)
{
	if (p == NULL)
		return NULL;

	poly_t * del_node;
	while( p->next != NULL )
	{
		del_node = p->next;
		p->next = del_node->next;
		free(del_node);
	}
	free(p);
	p = NULL;
	return p;
}

poly_t * add(poly_t * p1, poly_t * p2)
{
	poly_t * p3 = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->exp == p2->exp)
		{
			p3 = insert(p3, p1->coff + p2->coff, p1->exp);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			p3 = insert(p3, p1->coff, p1->exp);
			p1 = p1->next;
		}
		else
		{
			p3 = insert(p3, p2->coff, p2->exp);
			p2 = p2->next;
		}
	}

	while(p1 != NULL)
	{
		p3 = insert(p3, p1->coff, p1->exp);
		p1 = p1->next;
	}

	while(p2 != NULL)
	{
		p3 = insert(p3, p2->coff, p2->exp);
		p2 = p2->next;
	}

	return p3;
}
