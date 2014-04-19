/*
 * Algo 2 for pattern matching: Use table/graph for finding the pattern
 * 		Only "lower case" alphabets are allowed in the pattern string as
 *		the table is generated automatically. This can be expanded later
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMALPHA 26

static void gen_table(char * pat);
static void free_table();
static int get_state(int state, char c);
static int get_index(char * s);

static int * state_table = NULL;
static int alpha[NUMALPHA] = {0}; /* Stores the index of each alphabet & 0 is not present */
static int pat_len;

int main()
{
	char s[] = "abcaabaca";
	char pat[] = "aaba";

	pat_len = strlen(pat);
	gen_table(pat);

	printf("Index of pattern %s in string %s is: %d\n", pat, s, get_index(s));

	free_table();

	return 0;
}

/* Generate the state table */
static void gen_table(char * pat)
{

	int i, j, k, l;
	int c;
	int distinct_alpha = 0;
	char state_str[pat_len][pat_len];
	char state[pat_len+1];

	state_str[0][0] = '\0';
	for (i=1; i<pat_len ; ++i)
	{
		strcpy(state_str[i], state_str[i-1]);
		state_str[i][i-1] = pat[i-1];
		state_str[i][i] = '\0';
	}

	for (i=0; i<pat_len; ++i)
	{
		c = pat[i] - 'a';
		if (alpha[c] == 0)
		{
			/* Column needs to be inserted for character *pat */
			++distinct_alpha;
			alpha[c] = distinct_alpha;
			state_table = (int *) realloc(state_table, sizeof(int) * pat_len * distinct_alpha );
			if (state_table == NULL)
			{
				fprintf(stderr, "Error: Memory allocation failed.\n");
				exit(1);
			}

			for (j=0; j<pat_len ; ++j)
			{
				strcpy(state, state_str[j]);
				state[j] = pat[i];
				state[j+1] = '\0';

				for (k=j+1, l=0; k>=0; --k, ++l)
				{
					if (k==pat_len)
					{
						if (strcmp(state+l, pat) == 0)
						{
							state_table[pat_len*(distinct_alpha-1) + j] = -1;
							break;
						}
						continue;
					}

					if (strcmp(state+l, state_str[k]) == 0)
					{
						/* Indexing: state_table[len*row + col] */
						state_table[pat_len*(distinct_alpha-1) + j] = k;
						break;
					}
				}
			}
		}
	}

	printf("\n[State Table]\n");
	for (i=0; i<distinct_alpha ; ++i)
	{
		for (j=0; j<pat_len; ++j)
			printf("%2d ", state_table[pat_len*i + j]);
		printf("\n");
	}
	printf("\n\n");
}

static void free_table()
{
	free(state_table);
	state_table = NULL;
}

static int get_state(int state, char c)
{
	int row = alpha[c - 'a'] - 1;
	int col = state;

	if (row == -1)
		return 0;

	return state_table[pat_len*row + col];
}

/* Return the index of pattern in string s*/
static int get_index(char * s)
{
	int i;
	int state;

	state = 0;
	for (i=0; s[i]; ++i)
	{
		state = get_state(state, s[i]);
		if (state == -1)
			return i - pat_len + 1;
	}

	return -1;
}



