// InfixToPostfixWithParenthesis.cpp : Defines the entry point for the application.
//

#include "InfixToPostfixWithParenthesis.h"
#include "Stack.h"

using namespace std;

int precedance(char c) {
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	return -1;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
		return true;
	return false;
}

string infixToPostfix(string infix, Stack * st) {
	int i = 0;
	int j = 0;
	string postfix;
	while (infix[i] != '\0') {
		if (!isOperator(infix[i])) {
			postfix += infix[i++];
		}
		else {
			if (st->isEmpty() || st->stackTop() == '(' || infix[i] == '(') {
				st->push(infix[i++]);
			}
			else if (infix[i] == ')') {
				while (!st->isEmpty() && st->stackTop() != '(') {
					postfix += st->pop();
				}
				st->pop();
				i++;
			}
			else if (precedance(infix[i]) <= precedance(st->stackTop())) {
				postfix += st->pop();
				st->push(infix[i++]);
			}
		}
		cout << postfix << endl;
	}
	while (!st->isEmpty()) {
		postfix += st->pop();
	}
	return postfix;
}

int main()
{
	string infix = "x^y/(5*z)+2";
	Stack st = Stack();
	cout << "Postfix Expression is : " << infixToPostfix(infix, &st) << endl;
	string infix2 = "x^y/5*z+2";
	cout << "Postfix Expression is : " << infixToPostfix(infix2, &st) << endl;
	return 0;
}
