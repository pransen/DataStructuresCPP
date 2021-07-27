// StackArrayStructure.cpp : Defines the entry point for the application.
//

#include "StackArrayStructure.h"

using namespace std;

struct Stack {
	int size;
	int top;
	int* S;
};

void push(struct Stack* st, int data) {
	if (st->top == st->size - 1) {
		cout << "Stack Overflow! Can't push element : " << data << endl;
	}
	else {
		st->top++;
		st->S[st->top] = data;
		cout << "Pushed item : " << data << endl;
	}
}

int pop(struct Stack* st) {
	int returnVal = -1;
	if (st->top == -1) {
		cout << "Stack Underflow! Item can't popped" << endl;
	}
	else {
		returnVal = st->S[st->top--];
		cout << "Popped item : " << returnVal << endl;
	}
	return returnVal;
}

int peek(struct Stack st, int index) {
	int returnVal = -1;
	if (st.top - index + 1 < 0) {
		cout << "Invalid Index" << endl;
	}
	else {
		returnVal = st.S[st.top - index + 1];
	}
	return returnVal;
}

int stackTop(struct Stack st) {
	int returnVal = -1;
	if (st.top == -1) {
		cout << "Stack Underflow" << endl;
	}
	else {
		returnVal = st.S[st.top];
	}
	return returnVal;
}

bool isEmpty(struct Stack st) {
	return (st.top == -1);
}

bool isFull(struct Stack st) {
	return (st.top == st.size - 1);
}

struct Stack* createStack() {
	// Create stack on heap memory
	struct Stack * st = new struct Stack;
	cout << "Enter the desired size of the stack : " << endl;
	cin >> st->size;
	st->top = -1;
	st->S = new int[st->size];
	return st;
}

void display(struct Stack st) {
	cout << "--------------- Displaying Stack ---------------" << endl;
	for (int i = st.top; i >= 0; i--) {
		cout << st.S[i] << " ";
	}
	cout << endl << "------------------------------------------------" << endl;
}

int main()
{
	struct Stack* st = createStack();
	push(st, 5);
	push(st, 4);
	push(st, 3);
	push(st, 2);
	push(st, 1);
	display(*st);
	cout << "Item at index 3 is : " << peek(*st, 3) << endl;
	cout << "Item at the top of stack is : " << stackTop(*st) << endl;
	cout << "Is stack Full ? " << isFull(*st) << endl;
	pop(st);
	pop(st);
	pop(st);
	pop(st);
	cout << "Is stack Empty ? " << isEmpty(*st) << endl;
	cout << "Item at index 3 is : " << peek(*st, 3) << endl;
	cout << "Item at the top of stack is : " << stackTop(*st) << endl;
	return 0;
}
