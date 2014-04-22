/*
 * Circular Header Linked List implemented using arrays
 */

#include "05_cir_header_ll_arr.h"

#include <stdio.h>

#define MAX_LL_SIZE 20

static int start = -1;
static int empty = 0;

static int ll_data[MAX_LL_SIZE];
static int ll_link[MAX_LL_SIZE];

/* Private functions */
static void init_ll(void);

static void init_ll()
{
	int i;

	start = 0; /* Header is at 0 */
	ll_link[start] = start;

	empty = 1;
	for (i=1; i<MAX_LL_SIZE-1; ++i)
		ll_link[i] = i+1;
	ll_link[MAX_LL_SIZE-1] = -1;
}

/* Inserts at the end end of the list */
void insert_data(int data)
{
	if (start == -1)
		init_ll();

	if (empty == -1)
	{
		fprintf(stderr, "Error: No empty space available. Insert Failed.\n");
		return;
	}
	
	int last_node;
	int new_node;
	new_node = empty;
	empty = ll_link[empty];

	for (last_node = start; ll_link[last_node] != start; last_node = ll_link[last_node])
		;

	ll_data[new_node] = data;
	ll_link[new_node] = start;

	ll_link[last_node] = new_node;
}

void delete_data(int data)
{
	int node;
	int del_node;
	for (node = start; ll_link[node] != start; node = ll_link[node])
		if (ll_data[ll_link[node]] == data)
		{
			del_node = ll_link[node];
			ll_link[node] = ll_link[del_node];

			ll_link[del_node] = empty;
			empty = del_node;
			return;
		}

	printf("%d not found in the list, delete failed\n", data);
}

void print_ll()
{
	int node;
	printf("\n[List] : ");
	for (node = ll_link[start]; node != start; node = ll_link[node])
		printf("%d ", ll_data[node]);
	printf("\n");
}

int search_ll(int data)
{
	int loc;
	int node;
	for (loc=-1, node = ll_link[start]; node != start; node = ll_link[node])
	{
		++loc;
		if ( ll_data[node] == data )
			return loc;
	}
	return -1;
}

