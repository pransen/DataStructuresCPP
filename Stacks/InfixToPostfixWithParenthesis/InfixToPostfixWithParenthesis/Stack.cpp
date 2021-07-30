#include "Stack.h"

using namespace std;

void Stack::push(char data)
{
	Node* newNode = new Node(data);
	if (isFull()) {
		cout << "Stack Overflow!" << endl;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

char Stack::pop()
{
	char c = '-1';
	if (isEmpty()) {
		cout << "Stack Underflow!" << endl;
	}
	else {
		c = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
	}
	return c;
}

char Stack::stackTop() {
	if (top != nullptr)
		return top->data;
	return -1;
}

bool Stack::isEmpty()
{
	if (top == nullptr)
		return true;
	return false;
}

bool Stack::isFull()
{
	Node* newNode = new Node('-1');
	if (newNode == nullptr) {
		delete newNode;
		return true;
	}
	return false;
}
