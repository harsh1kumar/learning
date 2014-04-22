#include <stdio.h> 
#include "06_cir_header_ll.h"

int main()
{
	int i, j;

	insert_data(55);
	print_ll();

	insert_data(22);
	print_ll();

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

	
	delete_data(79);
	delete_data(77);
	delete_data(55);
	print_ll();

	i = 87;
	if ( (j=search_ll(i)) == -1)
		printf("\n%d is not present in the list\n", i);
	else
		printf("\n%d is present in the list at index: %d\n", i, j);

	i = 2;
	if ( (j=search_ll(i)) == -1)
		printf("%d is not present in the list\n", i);
	else
		printf("%d is present in the list at index: %d\n", i, j);
	
	return 0;
}


  
