#include <stdio.h>
#include "02_ll_sorted_array.h"

void multi_by_10(int i);

int main()
{
	int i;

	print_ll();
	traverse_ll(multi_by_10);

	init_ll(10);
	print_ll();

	insert_data(20);
	insert_data(50);
	insert_data(50);
	insert_data(30);
	insert_data(15);
	insert_data(45);
	insert_data(25);
	insert_data(40);
	insert_data(35);
	insert_data(17);
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
	printf("\n\nDeleting %d", i);
	delete_data(i);
	print_ll();

	i = 10;
	printf("\n\nDeleting %d", i);
	delete_data(i);
	print_ll();
	
	i = 35;
	printf("\n\nDeleting %d", i);
	delete_data(i);
	print_ll();

	i = 50;
	printf("\n\nDeleting %d", i);
	delete_data(i);
	print_ll();

	return 0;
}

void multi_by_10(int i)
{
	printf("%d ", i*10);
}

