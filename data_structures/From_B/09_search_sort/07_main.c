#include "07_hash_table_chain.h"

#include <stdio.h>

int main()
{
	int i;

	insert_data(1000);
	insert_data(2432);
	insert_data(5433);
	insert_data(3432);
	insert_data(3322);
	insert_data(3232);
	insert_data(5454);
	insert_data(6564);
	insert_data(7655);
	insert_data(8675);
	insert_data(9798);
	insert_data(1222);
	insert_data(2122);

	printf("\n\n");

	i = 5433;
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));

	i = 5422;
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));

	i = 3432;
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));

	i = 3431;
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));

	i = 5433;
	delete_data(i);
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));
	insert_data(i);
	printf("%d %sfound.\n", i, (search_data(i) ? "" : "not "));
	
	i = 5431;
	delete_data(i);
	
	return 0;
}


