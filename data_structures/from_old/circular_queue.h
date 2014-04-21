#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

class Circular_Q
{
	const static int queue_size = 10;
	int queue[queue_size];
	int front; /* Front = Empty area before the first element */
	int rear; /* Rear = Last element*/
public:
	Circular_Q();

	void insert(const int& data);
	int remove();
	inline bool is_empty() const;
	inline bool is_full() const;
};

inline bool Circular_Q::is_empty() const
{
	/* Empty means front & rear is at the same place */
	return (front == rear);
}

inline bool Circular_Q::is_full() const
{
	return ((front == rear+1) || (front==0 && rear==queue_size-1));
}

#endif // CIRCULAR_QUEUE_H
