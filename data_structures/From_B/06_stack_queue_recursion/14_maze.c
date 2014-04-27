/*
 * The maze problem: Maze represented by a 2d array/matrix.
 * 		0 is empty space, 1 is obstacle
 *		Task is to reach from top left corner to bottom right corner
 */

#include <stdio.h>

#define MAZE_SIDE 15
#define MAX_OP 4
#define MAX_PATH 35

static int maze[MAZE_SIDE][MAZE_SIDE] = { 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,1,0,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,1,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
					};

struct cood
{
	int x;
	int y;
};

static struct cood op_cood[MAX_OP] = {	{0, 1},		/* right */
					{1, 0},		/* down */
					{0, -1},	/* left */
					{-1, 0}		/* up */
				};


int main()
{
	int i, j;
	struct cood curr;
	struct cood next;
	struct cood final = {MAZE_SIDE-2, MAZE_SIDE-2};
	struct cood path[MAX_PATH];
	int steps;
	int op;

	printf("\n\t*** MAZE ***\n");
	for (i=0; i<MAZE_SIDE; ++i)
	{
		for (j=0; j<MAZE_SIDE; ++j)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
	printf("\n");

	op = 0;
	curr.x = 1;
	curr.y = 1;
	maze[1][1] = 2;
	steps = 0;
	path[steps].x = 1;
	path[steps].y = 1;

	while (!(curr.x == final.x && curr.y == final.y) && steps < MAX_PATH-1)
	{
		while (op < MAX_OP)
		{
			next.x = curr.x + op_cood[op].x;
			next.y = curr.y + op_cood[op].y;

			if (maze[next.x][next.y] == 0)
				break;
			else
				++op;
		}

		if (op < MAX_OP)
		{
			curr.x = next.x;
			curr.y = next.y;
			++steps;
			path[steps].x = next.x;
			path[steps].y = next.y;
			maze[next.x][next.y] = 2;
			op = 0;
		}
		else
		{
			--steps;
			maze[curr.x][curr.y] = 0;
			curr.x = path[steps].x;
			curr.y = path[steps].y;
			++op;
		}
	}

	if (curr.x == final.x && curr.y == final.y)
	{
		printf("Successfully traversed maze.\nPath = ");
		for (i=0; i<=steps; ++i)
			printf("(%d, %d)\n", path[i].x, path[i].y);
		printf("\n\n");
	}
	else
		printf("Failed to traversed maze.\n\n");

	printf("\n\t*** MAZE ***\n");
	for (i=0; i<MAZE_SIDE; ++i)
	{
		for (j=0; j<MAZE_SIDE; ++j)
			printf("%d ", maze[i][j]);
		printf("\n");
	}

	return 0;
}




