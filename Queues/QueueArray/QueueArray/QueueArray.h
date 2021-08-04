// QueueArray.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

class Queue {
private:
	int front;
	int rear;
	int size;
	int* Q;
public:
	Queue(int);
	void enqueue(int);
	int dequeue();
	bool isFull();
	bool isEmpty();
};