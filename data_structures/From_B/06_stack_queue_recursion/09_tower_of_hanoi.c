/*
 * Tower of Hanoi
 */

#include <stdio.h>

int toh_recur(int n, char * beg, char * aux, char * end);

int main()
{
	printf("\nNo. of Moves = %d\n", toh_recur(3, "BEG", "AUX", "END") );

	return 0;
}

/* Returns number of moves & prints the moves */
int toh_recur(int n, char * beg, char * aux, char * end)
{
	int moves;

	if (n == 1)
	{
		printf("%s->%s : ", beg, end);
		return 1;
	}

	moves = toh_recur(n-1, beg, end, aux);

	printf("%s->%s : ", beg, end);
	++moves;

	moves += toh_recur(n-1, aux, beg, end);

	return moves;
}


