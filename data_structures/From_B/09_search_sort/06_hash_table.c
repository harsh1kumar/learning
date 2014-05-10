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


#include "06_hash_table.h"

#include <stdio.h>


/* Common Hash function for all 3 Hash Tables */
#define get_hash(x)	((x) % (HASH_DIVISOR))


/******************
 * Linear Probing
 ******************/
static int table_lp[HASH_DIVISOR]; /* static, therefore assumed to be zero initialized */

void insert_lp(int data)
{
	int hash = get_hash(data);

	printf("Inserting %d Hash = %d\n", data, hash);

	do
	{
		if (table_lp[hash] == 0)
		{
			table_lp[hash] = data;
			return;
		}

		++hash;
		hash = get_hash(hash);
		printf("\tCollision, try hash = %d\n", hash);

	} while ( hash != get_hash(data) );

	/* If here, then table is full */
	fprintf(stderr, "Error: Insert failed while adding %d. Table is full.\n", data);
}

/* Returns 1 if found 0 otherwise */
int search_lp(int data)
{
	int hash = get_hash(data);

	do
	{
		if (table_lp[hash] == data)
		{
			return 1;
		}

		if (table_lp[hash] == 0)
		{
			return 0;
		}

		++hash;
		hash = get_hash(hash);

	} while ( hash != get_hash(data));

	return 0;
}


/********************
 * Quadratic Probing 
 ********************/

static int table_qp[HASH_DIVISOR]; /* static, therefore assumed to be zero initialized */

void insert_qp(int data)
{
	int hash = get_hash(data);
	int i = 0;

	printf("Inserting %d Hash = %d\n", data, hash);

	do
	{
		if (table_qp[hash] == 0)
		{
			table_qp[hash] = data;
			return;
		}

		++i;
		hash = get_hash( data + (i*i) );
		printf("\tCollision, try hash = %d\n", hash);

	} while ( i < HASH_DIVISOR );

	/* If here, then table is full */
	fprintf(stderr, "Error: Insert failed while adding %d.\n", data);
}

/* Returns 1 if found 0 otherwise */
int search_qp(int data)
{
	int hash = get_hash(data);
	int i = 0;

	do
	{
		if (table_qp[hash] == data)
		{
			return 1;
		}

		if (table_qp[hash] == 0)
		{
			return 0;
		}

		++i;
		hash = get_hash( data + (i*i) );

	} while ( i < HASH_DIVISOR );

	return 0;
}



/*****************
 * Double Hashing
 *****************/

static int table_dh[HASH_DIVISOR]; /* static, therefore assumed to be zero initialized */

#define HASH_DIVISOR_2 23

/* Second Hash function for Double Hashing */
#define get_hash2(x)	((x) % (HASH_DIVISOR_2))

void insert_dh(int data)
{
	int hash = get_hash(data);
	int i = 0;

	printf("Inserting %d Hash = %d\n", data, hash);

	do
	{
		if (table_dh[hash] <= 0)
		{
			table_dh[hash] = data;
			return;
		}

		++i;
		hash = get_hash( get_hash(data) + (i * get_hash2(data)) );
		printf("\tCollision, try hash = %d\n", hash);

	} while ( i < HASH_DIVISOR );

	/* If here, then table is full */
	fprintf(stderr, "Error: Insert failed while adding %d.\n", data);
}


/* Returns 1 if found 0 otherwise */
int search_dh(int data)
{
	int hash = get_hash(data);
	int i = 0;

	do
	{
		if (table_dh[hash] == data)
		{
			return 1;
		}

		if (table_dh[hash] == 0)
		{
			return 0;
		}

		++i;
		hash = get_hash( get_hash(data) + (i * get_hash2(data)) );

	} while ( i < HASH_DIVISOR );

	return 0;
}



