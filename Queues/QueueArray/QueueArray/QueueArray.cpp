// QueueArray.cpp : Defines the entry point for the application.
//

#include "QueueArray.h"

using namespace std;

Queue::Queue(int size) {
	this->size = size;
	this->front = -1;
	this->rear = -1;
	this->Q = new int[size];
}

void Queue::enqueue(int data)
{
	if (!isFull()) {
		this->rear += 1;
		this->Q[this->rear] = data;
		cout << "Enqueued data : " << data << endl;
	}
	else {
		cout << "Queue is full!" << endl;
	}
}

int Queue::dequeue()
{
	int x = -1;
	if (!isEmpty()) {
		this->front += 1;
		x = this->Q[this->front];
		cout << "Dequeued data : " << x << endl;
	}
	else {
		cout << "Empty queue!" << endl;
		// reset the front and rear pointers when they have reached the end of the array
		this->front = this->rear = -1;
	}
	return x;
}

bool Queue::isFull()
{
	if (this->rear == this->size - 1)
		return true;
	return false;
}

bool Queue::isEmpty()
{
	if (this->front == this->rear)
		return true;
	return false;
}

int main()
{
	Queue q{ 5 };
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(1);
	q.enqueue(0);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(3);
	cout << "Hello CMake." << endl;
	return 0;
}

