// StackLinkedListClass.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
	friend class LinkedList;
};


class LinkedList {
private:
	Node* top;
public:
	LinkedList() {
		this->top = nullptr;
	};
	void push(int);
	int pop();
	int peek(int);
	bool isEmpty();
	bool isFull();
	void display();
	int stackTop();
};