/*
 * Matrix Multiplication
 */

#include <stdio.h>
#include <stdlib.h>

static void mul(int *** m1p, int *** m2p, int ***m3p, int m, int n, int p);
static void matmul(int ** m1, int ** m2, int ** m3, int m, int p, int n);
static int ** alloc_2d(int m, int n);
static int ** free_2d(int ** p, int rows);

int main()
{
	int ** m1, ** m2, ** m3;
	int m, p, n;


	/* 1st Matrix Multiplication */
	m = 2;
	p = 2;
	n = 3;

	m1 = alloc_2d(m, p);
	m2 = alloc_2d(p, n);
	m3 = alloc_2d(m, n);

	m1[0][0] = 1;
	m1[0][1] = 3;
	m1[1][0] = 2;
	m1[1][1] = 4;

	m2[0][0] = 2;
	m2[0][1] = 0;
	m2[0][2] = -4;
	m2[1][0] = 3;
	m2[1][1] = 2;
	m2[1][2] = 6;

	mul(&m1, &m2, &m3, m, n, p);

	/* 2nd Matrix Multiplication */
	m = 2;
	p = 3;
	n = 4;

	m1 = alloc_2d(m, p);
	m2 = alloc_2d(p, n);
	m3 = alloc_2d(m, n);

	m1[0][0] = 4;
	m1[0][1] = -3;
	m1[0][2] = 5;
	m1[1][0] = 6;
	m1[1][1] = 1;
	m1[1][2] = -2;

	m2[0][0] = 2;
	m2[0][1] = 3;
	m2[0][2] = -7;
	m2[0][3] = -3;
	m2[1][0] = 5;
	m2[1][1] = -1;
	m2[1][2] = 6;
	m2[1][3] = 2;
	m2[2][0] = 0;
	m2[2][1] = 3;
	m2[2][2] = -2;
	m2[2][3] = 1;

	mul(&m1, &m2, &m3, m, n, p);

	return 0;
}

/* Will free the memory for m1, m2, & m3 */
static void mul(int *** m1p, int *** m2p, int ***m3p, int m, int n, int p)
{
	int i, j;

	matmul(*m1p, *m2p, *m3p, m, p, n);
	for (i=0; i<m; ++i)
	{
		for (j=0; j<n; ++j)
			printf("%02d ", (*m3p)[i][j]);
		printf("\n");
	}
	printf("\n");

	*m1p = free_2d(*m1p, m);
	*m2p = free_2d(*m2p, p);
	*m3p = free_2d(*m3p, m);
}

static int ** alloc_2d(int m, int n)
{
	int ** p;
	int i;

	p = (int **)malloc( m*sizeof(int) );
	for (i=0; i<m; ++i)
		p[i] = (int *)malloc( n*sizeof(int) );

	return p;
}

static int ** free_2d(int ** p, int rows)
{
	int i;
	for (i=0; i<rows; ++i)
		free(p[i]);
	free(p);

	return NULL;
}

/*
 * m1 : m x p
 * m2 : p x n
 * m3 : m x n
 *
 * m3 = m1 x m2
 *
 * User must ensure that the arguments satisfy above. Otherwise behaviour & result can be anything.
 */
static void matmul(int ** m1, int ** m2, int ** m3, int m, int p, int n)
{
	int i, j, k;

	for (i=0; i<m; ++i)
	{
		for (j=0; j<n; ++j)
		{
			m3[i][j] = 0;
			for (k=0; k<p; ++k)
				m3[i][j] += m1[i][k] * m2[k][j];
		}
	}
}


