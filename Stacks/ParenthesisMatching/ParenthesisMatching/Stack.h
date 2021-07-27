#pragma once
#include<iostream>

class Node {
private:
	char data;
	Node* next;
public:
	Node(char data) {
		this->next = nullptr;
		this->data = data;
	};
	friend class Stack;
};

class Stack {
private:
	Node* top;
public:
	Stack() {
		this->top = nullptr;
	}
	void push(char);
	char pop();
	bool isEmpty();
	bool isFull();
};
