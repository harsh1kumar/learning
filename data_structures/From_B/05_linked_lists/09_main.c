#include <stdio.h> 
#include "09_header_doubly_ll.h"

int main()
{
	int i;

	print_ll();
	insert_data(2);
	print_ll();

	insert_data(55);
	insert_data(22);
	insert_data(19);
	insert_data(5);
	insert_data(50);
	insert_data(87);
	insert_data(79);
	insert_data(33);
	insert_data(99);
	insert_data(29);
	insert_data(8);
	print_ll();

	i = 2;
	printf("\nIndex of %d is : %d\n", i, search_ll(i));
	i = 55;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 22;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 19;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 99;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 29;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 8;
	printf("Index of %d is : %d\n", i, search_ll(i));
	i = 9;
	printf("Index of %d is : %d\n", i, search_ll(i));

	i = 2;
	printf("\nDeleting %d..", i);
	delete_data(i);
	print_ll();

	i = 79;
	printf("\nDeleting %d..", i);
	delete_data(i);
	print_ll();

	i = 2;
	printf("\nDeleting %d..", i);
	delete_data(i);
	print_ll();

	i = 8;
	printf("\nDeleting %d..", i);
	delete_data(i);
	print_ll();

	delete_data(29);
	print_ll();
	delete_data(99);
	print_ll();
	delete_data(33);
	print_ll();
	delete_data(87);
	print_ll();
	delete_data(50);
	print_ll();
	delete_data(55);
	print_ll();
	delete_data(22);
	print_ll();
	delete_data(5);
	print_ll();
	delete_data(19);
	print_ll();
	delete_data(25);
	print_ll();

	return 0;
}
 
