// InfixToPostfix.cpp : Defines the entry point for the application.
//

#include "InfixToPostfix.h"
#include "Stack.h"

using namespace std;

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

int precedance(char c) {
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return -1;
}

string infixToPostfix(string infix, Stack * st) {
	int i = 0;
	string postfix;
	while (infix[i] != '\0') {
		if (!isOperator(infix[i])) {
			postfix += infix[i++];
		}
		else {
			if (st->isEmpty()) {
				st->push(infix[i++]);
			}
			else if (precedance(infix[i]) > precedance(st->stackTop())) {
				st->push(infix[i++]);
			}
			else {
				postfix += st->pop();
			}
		}
	}
	while (!st->isEmpty()) {
		postfix += st->pop();
	}
	postfix += '\0';
	return postfix;
}

int main()
{
	string expression = "a+b*c-d/e";
	Stack st = Stack();
	cout << "Postfix expression is : " << infixToPostfix(expression, &st) << endl;
	return 0;
}
