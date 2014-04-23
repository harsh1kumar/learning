/*
 * Josephus Problem:
 * 	Jose(n, m):
 * 		n = Total number of players
 * 		m = Eliminate every mth player
 * 
 * Circualr Linked List will be used
 */

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * next;
};

static struct ll_node * start = NULL;

static int jose(int n, int m);
void insert_data(int data);
void delete_data(int data);

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s [num_players] [mth elimination]\n", *argv);
		return 1;
	}

	printf("Total Players: %d, Eliminate every %d(th) player.\n", atoi(argv[1]), atoi(argv[2]));
	printf("Last player standing is: %d\n", jose(atoi(argv[1]), atoi(argv[2])) );

	return 0;
}

static int jose(int n, int m)
{
	int i;

	for (i=1; i<=n; ++i)
		insert_data(i);

	while(start->next != start)
	{
		for (i=1; i<m; ++i)
			start = start->next;
		delete_data(start->data);
	}
	return start->data;

}

/* Insert at the end of the list */
void insert_data(int data)
{
	struct ll_node * new_node;
	struct ll_node * node;

	new_node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(EXIT_FAILURE);
	}

	new_node->data = data;

	if (start == NULL)
	{
		start = new_node;
		new_node->next = start;
		return;
	}

	for (node = start; node->next != start; node = node->next)
		;

	new_node->next = node->next;
	node->next = new_node;
	return;
}

void delete_data(int data)
{
	if ( start != NULL)
	{
		struct ll_node * node;
		struct ll_node * del_node;

		if (start->data == data)
		{
			del_node = start;
			if (start->next != start)
			{
				for (node = start; node->next != start; node = node->next)
					;
				start = start->next;
				node->next = start;
				
			}
			else
				start = NULL;
			free(del_node);
			return;
			
		}

		for (node = start; node->next != start; node = node->next)
		{
			if (node->next->data == data)
			{
				del_node = node->next;
				node->next = del_node->next;

				free(del_node);
				return;
			}
		}
	}
	printf("%d not found in list\n", data);
}
