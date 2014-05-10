/*
 * Hash Table with chaining for collision resolution
 */


#include "07_hash_table_chain.h"

#include <stdio.h>
#include <stdlib.h>

#define HASH_DIVISOR 11

static int get_hash(int data);
static void hash_table_init();


struct node
{
	int data;
	struct node * next;
};

static struct node * table[HASH_DIVISOR];


void insert_data(int data)
{
	int hash = get_hash(data);
	static int is_initialized = 0; /* Keeps track of whether table has been initialized */
	struct node * ptr;
	struct node * new_node;

	printf("Inserting %d Hash = %d\n", data, hash);

	if ( !is_initialized )
	{
		hash_table_init();
		is_initialized = 1;
	}

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;

	if (table[hash] == NULL)
	{
		table[hash] = new_node;
		return;
	}

	printf("\tCollision\n");
	for (ptr = table[hash]; ptr->next != NULL; ptr = ptr->next)
	{
		printf("\tCollision\n");
	}

	ptr->next = new_node;
	return;
}

int delete_data(int data)
{
	int hash = get_hash(data);
	struct node * ptr;
	struct node * del_node;

	printf("Deleting %d\n", data);

	if ( table[hash] == NULL )
	{
		printf("%d not found\n", data);
		return 0;
	}

	if (table[hash]->data == data)
	{
		del_node = table[hash];
		table[hash] = del_node->next;
		free(del_node);
		return 1;
	}

	for (ptr = table[hash]; ptr->next != NULL; ptr = ptr->next)
	{
		if (ptr->next->data == data)
		{
			del_node = ptr->next;
			ptr->next = del_node->next;
			free(del_node);
			return 1;
		}
	}

	printf("%d not found\n", data);
	return 0;
}

int search_data(int data)
{
	int hash = get_hash(data);
	struct node * ptr;

	printf("Seaching %d\n", data);

	for (ptr = table[hash]; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data == data)
		{
			return 1;
		}
	}

	return 0;
}

static int get_hash(int data)
{
	return data % HASH_DIVISOR;
}

static void hash_table_init()
{
	int i;

	printf("Initializing table\n");

	for (i=0; i<HASH_DIVISOR; ++i)
	{
		table[i] = NULL;
	}
}



