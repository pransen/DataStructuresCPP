// StacksArrays.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

class Stack {
private:
	int top;
	int size;
	int* S;
public:
	Stack(int);
	void push(int);
	int pop();
	bool isFull();
	bool isEmpty();
	int peek(int);
	int stackTop();
	void display();
};
