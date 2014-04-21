#include <stdio.h>
#include "01_ll_array.h"

void multi_by_10(int i);

int main()
{
	int i;

	print_ll();
	traverse_ll(multi_by_10);

	init_ll(10);
	print_ll();

	insert_at_end(20);
	insert_at_end(50);
	insert_at_end(30);
	insert_at_end(15);
	insert_at_begin(45);
	insert_at_end(25);
	insert_at_end(40);
	insert_after_d(35, 35);
	insert_after_d(15, 17);
	print_ll();

	printf("\n[List multiplied by 10] : ");
	traverse_ll(multi_by_10);
	printf("\n\n");

	i = 10;
	printf("%d is%spresent in the list\n", i, (search_ll(i) >= 0 ? " " : " not "));
	i = 11;
	printf("%d is%spresent in the list\n", i, (search_ll(i) >= 0 ? " " : " not "));
	i = 15;
	printf("%d is%spresent in the list\n", i, (search_ll(i) >= 0 ? " " : " not "));
	i = 50;
	printf("%d is%spresent in the list\n", i, (search_ll(i) >= 0 ? " " : " not "));
	i = -1;
	printf("%d is%spresent in the list\n", i, (search_ll(i) >= 0 ? " " : " not "));

	i = 100;
	printf("\n\nDeleted %d", i);
	delete_data(i);
	print_ll();

	i = 10;
	printf("\n\nDeleted %d", i);
	delete_data(i);
	print_ll();
	
	i = 35;
	printf("\n\nDeleted %d", i);
	delete_data(i);
	print_ll();

	i = 40;
	printf("\n\nDeleted %d", i);
	delete_data(i);
	print_ll();

	return 0;
}

void multi_by_10(int i)
{
	printf("%d ", i*10);
}

