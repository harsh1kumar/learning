/*
 * Hash Table with Open Addressing:
 *
 *	3 Different Hash Tables are available with 3 different collision resolution methods:
 *		1.) Linear Probing
 *		2.) Quadratic Probing (Is buggy)
 *		3.) Double Hashing (Is buggy)
 *
 *	NOTE 1: Number of items in the hash table should be atmost HASH_DIVISOR
 *	------
 *	NOTE 2: Zero cannot be inserted into the hash tables. Zero denotes empty.
 *	------
 */

#ifndef H_06_HASH_TABLE
#define H_06_HASH_TABLE

#define HASH_DIVISOR 11

/******************
 * Linear Probing
 ******************/
void insert_lp(int data);
int search_lp(int data); /* Returns 1 if found 0 otherwise */


/********************
 * Quadratic Probing 
 ********************/
void insert_qp(int data);
int search_qp(int data); /* Returns 1 if found 0 otherwise */


/*****************
 * Double Hashing
 *****************/
void insert_dh(int data);
int search_dh(int data); /* Returns 1 if found 0 otherwise */


#endif // H_06_HASH_TABLE

