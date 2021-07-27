// StackLinkedListClass.cpp : Defines the entry point for the application.
//

#include "StackLinkedListClass.h"

using namespace std;

void LinkedList::push(int data) {
	Node* newNode = new Node(data);
	if (newNode == nullptr) {
		cout << "Stack Overflow! Cannot push element : " << data << endl;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

int LinkedList::pop() {
	int returnVal = -1;
	if (top == nullptr) {
		cout << "Stack Underflow! Cannot pop elements from stack" << endl;
	}
	else {
		Node* temp = top;
		top = top->next;
		returnVal = temp->data;
		delete temp;
	}
	return returnVal;
}

int LinkedList::peek(int index) {
	int returnVal = -1;
	Node* temp = top;
	for (int i = 0; temp != nullptr && i < index - 1; i++) {
		temp = temp->next;
	}
	if (temp == nullptr) {
		cout << "Invalid index" << endl;
	}
	else {
		returnVal = temp->data;
	}
	return returnVal;
}

int LinkedList::stackTop() {
	int returnVal = -1;
	if(top == nullptr) {
		cout << "Stack Underflow" << endl;
	}
	else {
		returnVal = top->data;
	}
	return returnVal;
}

bool LinkedList::isFull() {
	bool isfull = false;
	Node* temp = new Node(-1);
	if (temp == nullptr) {
		isfull = true;
	}
	delete temp;
	return isfull;
}

bool LinkedList::isEmpty() {
	return (top == nullptr);
}

void LinkedList::display() {
	Node* temp = top;
	cout << "-------------- Displaying Stack -------------" << endl;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl << "---------------------------------------------" << endl;
}

