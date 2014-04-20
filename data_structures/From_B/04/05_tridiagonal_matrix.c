/*
 * n-square tridiagonal matrix
 */

#include <stdio.h>

#define N 5

int main()
{
	int mat[N][N];
	int i, j;

	for (i=0; i<N; ++i)
		for (j=0; j<N; ++j)
			mat[i][j] = 0;
	
	mat[0][0] = 2;
	mat[0][1] = 22;

	mat[1][0] = -13;
	mat[1][1] = 77;
	mat[1][2] = 4;

	mat[2][1] = 3;
	mat[2][2] = 87;
	mat[2][3] = 99;

	mat[3][2] = 42;
	mat[3][3] = 6;
	mat[3][4] = 9;

	mat[4][3] = 7;
	mat[4][4] = 29;

	/* Printing matrix */
	printf("-------\nMatrix:\n-------\n\n");
	for (i=0; i<N; ++i)
	{
		for (j=0; j<N; ++j)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}
	printf("\n");

	/* Now efficiently storing matrix in an array */
	int arr[2 + (3*(N-2))+ 2];
	int k;

	k=0;
	for (i=0; i<N; ++i)
	{
		for (j=i-1; j<=i+1; ++j)
		{
			if (j < 0 || j >= N)
				continue;
			arr[k++] = mat[i][j];
		}
	}

	printf("k = %d\nSize of arr = %d\narr = ", k, (sizeof arr)/(sizeof arr[0]));
	for (i=0; i<(sizeof arr)/(sizeof arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n\n");

	for (i=0; i<N; ++i)
	{
		for (j=0; j<N; ++j)
		{
			if (i==j || i==j-1 || i==j+1)
				printf("%3d ", arr[2 + ((i-1)*3) + j-i+1]);
			else
				printf("%3c ", ' ');
		}
		printf("\n");
	}

	return 0;
}


