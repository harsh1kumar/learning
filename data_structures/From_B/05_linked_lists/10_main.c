#include <stdio.h> 
#include "10_doubly_ll.h"

int main()
{
	print_ll();
	insert_data(10);
	print_ll();

	insert_data(20);
	insert_data(30);
	insert_data(15);
	insert_data(40);
	insert_data(50);
	insert_data(25);
	insert_data(60);
	print_ll();

	delete_data(100);
	print_ll();

	delete_data(15);
	print_ll();

	delete_data(25);
	print_ll();

	delete_data(10);
	print_ll();

	delete_data(20);
	print_ll();

	delete_data(60);
	print_ll();

	delete_data(50);
	print_ll();

	delete_data(30);
	print_ll();

	delete_data(40);
	print_ll();

	delete_data(40);
	print_ll();

	return 0;
}

