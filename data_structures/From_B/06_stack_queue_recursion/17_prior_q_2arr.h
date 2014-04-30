/*
 * Priority Queue implemented using a 2d array where each row serves as a circular queue
 * 	front & rear are arrays of size max_prior
 * 	pq is 2d array of size (max_prior x Q_SIZE)
 */

#ifndef H_17_PRIOR_Q2ARR 
#define H_17_PRIOR_Q2ARR

#define Q_SIZE 3

void pq_init(int max_prior, int * front, int * rear);
void pq_insert(int pq[][Q_SIZE], int max_prior, int * front, int * rear, int data, int prior);
int pq_delete(int pq[][Q_SIZE], int max_prior, int * front, int * rear);

#endif // H_17_PRIOR_Q2ARR
