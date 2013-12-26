/*
 * Program to test queue
 */

#include <iostream>
#include "circular_queue.h"

using namespace std;

void print_queue_status(const Circular_Q& q)
{
	cout 	<< "Queue is " << (q.is_empty() ? "empty ": "not empty ")
		<< "& " << (q.is_full() ? "full.\n": "not full.\n");
}

int main()
{
	Circular_Q my_q;
	print_queue_status(my_q);
	for (int i=0; i<9; ++i)
	{
		my_q.insert(i);
		cout << "Inserted: " << i << "\t";
		print_queue_status(my_q);
	}
	// my_q.insert(10); // Will overflow the queue

	cout << "\n\n";

	for (int i=9; i>0; --i)
	{
		cout << "Removed: " << my_q.remove() << "\t";
		print_queue_status(my_q);
	}
	//my_q.remove(); // Queue is empty, so will generate error

	return 0;
}
