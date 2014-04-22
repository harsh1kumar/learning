#ifndef H_07_POLY 
#define H_07_POLY

typedef struct poly
{
	int coff;
	int exp;
	struct poly * next;
} poly_t;

poly_t * insert(poly_t * p, int coff, int exp);
poly_t * delete_poly(poly_t * p);

void print_poly(poly_t * p);

poly_t * add(poly_t * p1, poly_t * p2);

#endif // H_07_POLY
