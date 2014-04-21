/*
 *
 */

#include <iostream>
#include <cstdlib>
#include "circular_queue.h"

using namespace std;

Circular_Q::Circular_Q() : front(0), rear(0) {}

void Circular_Q::insert(const int& data)
{
	if (is_full())
	{
		cout << "Queue overflow!!\nExiting..\n";
		exit(1);
	}
	if (rear == queue_size-1)
		rear = 0;
	else
		++rear;
	queue[rear] = data;
}

int Circular_Q::remove()
{
	if (is_empty())
	{
		cout << "Queue empty!!\nExiting..\n";
		exit(1);
	}
	if (front == queue_size-1)
		front = 0;
	else
		++front;
	return queue[front];
}


