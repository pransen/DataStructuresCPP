// Author : Prantik Sen
// Implementation of Stack using Arrays
// StacksArrays.cpp : Defines the entry point for the application.


#include "StacksArrays.h"

using namespace std;

Stack::Stack(int size) {
	this->size = size;
	this->top = -1;
	this->S = new int[size];
}

void Stack::push(int x) {
	if (!isFull()) {
		this->top++;
		this->S[top] = x;
		cout << "Pushed element : " << x << endl;
	}
	else {
		cout << "Stack Overflow! Element could not be pushed : " << x << endl;
	}
}

int Stack::pop() {
	int returnVal = -1;
	if (!isEmpty()) {
		returnVal = this->S[this->top];
		this->top--;
		cout << "Popped element : " << returnVal << endl;
	}
	else {
		cout << "Stack Underflow! Items can't be popped" << endl;
	}
	return returnVal;
}

bool Stack::isFull() {
	if (this->top == this->size - 1)
		return true;
	return false;
}

bool Stack::isEmpty() {
	if (this->top == -1)
		return true;
	return false;
}

int Stack::peek(int index) {
	int returnVal = -1;
	if (this->top - index + 1 < 0) {
		cout << "Invalid Index" << endl;
	}
	else {
		returnVal = this->S[this->top - index + 1];
	}
	return returnVal;
}

int Stack::stackTop() {
	if (!isEmpty()) {
		return this->S[this->top];
	}
	return -1;
}

void Stack::display() {
	for (int i = this->top; i >= 0; i--) {
		cout << this->S[i] << " ";
	}
	cout << endl;
}

int main()
{
	Stack st{ 5 };
	st.push(4);
	st.push(3);
	st.push(2);
	st.push(1);
	st.push(0);
	st.push(14);
	cout << "Peek element from index 3 : "<< st.peek(3) << endl;
	cout << "Topmost element is  : " << st.stackTop() << endl;
	st.display();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.pop();

	return 0;
}
