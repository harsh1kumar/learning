#include <stdio.h>

#include "06_hash_table.h"

int main()
{
	int i;

	/* Linear Probing */

	printf("\n\nLP\n\n");

	insert_lp(1000);
	insert_lp(2432);
	insert_lp(5433);
	insert_lp(3432);
	insert_lp(3322);
	insert_lp(3232);
	insert_lp(5454);
	insert_lp(6564);
	insert_lp(7655);
	insert_lp(8675);
	insert_lp(9798);
	insert_lp(1222);
	insert_lp(2122);

	printf("\n\n");

	i = 5433;
	printf("%d %sfound.\n", i, (search_lp(i) ? "" : "not "));

	i = 5422;
	printf("%d %sfound.\n", i, (search_lp(i) ? "" : "not "));

	i = 3432;
	printf("%d %sfound.\n", i, (search_lp(i) ? "" : "not "));

	i = 3431;
	printf("%d %sfound.\n", i, (search_lp(i) ? "" : "not "));


	/* Quadratic Probing */

	printf("\n\nQP\n\n");

	insert_qp(1000);
	insert_qp(2432);
	insert_qp(5433);
	insert_qp(3432);
	insert_qp(3322);
	insert_qp(3232);
	insert_qp(5454);
	insert_qp(6564);
	insert_qp(7655);
	insert_qp(8675);
	insert_qp(9798);
	insert_qp(1222);
	insert_qp(2122);

	printf("\n\n");

	i = 5433;
	printf("%d %sfound.\n", i, (search_qp(i) ? "" : "not "));

	i = 5422;
	printf("%d %sfound.\n", i, (search_qp(i) ? "" : "not "));

	i = 3432;
	printf("%d %sfound.\n", i, (search_qp(i) ? "" : "not "));

	i = 3431;
	printf("%d %sfound.\n", i, (search_qp(i) ? "" : "not "));


	/* Double Hashing */

	printf("\n\nDH\n\n");

	insert_dh(1000);
	insert_dh(2432);
	insert_dh(5433);
	insert_dh(3432);
	insert_dh(3322);
	insert_dh(3232);
	insert_dh(5454);
	insert_dh(6564);
	insert_dh(7655);
	insert_dh(8675);
	insert_dh(9798);
	insert_dh(1222);
	insert_dh(2122);

	printf("\n\n");

	i = 5433;
	printf("%d %sfound.\n", i, (search_dh(i) ? "" : "not "));

	i = 5422;
	printf("%d %sfound.\n", i, (search_dh(i) ? "" : "not "));

	i = 3432;
	printf("%d %sfound.\n", i, (search_dh(i) ? "" : "not "));

	i = 3431;
	printf("%d %sfound.\n", i, (search_dh(i) ? "" : "not "));

	return 0;
}


