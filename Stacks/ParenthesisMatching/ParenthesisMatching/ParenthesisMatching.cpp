// ParenthesisMatching.cpp : Defines the entry point for the application.
//

#include "ParenthesisMatching.h"
#include "Stack.h"

using namespace std;

// For parenthesis matching
bool isBalanced(Stack * st, string expression) {
	for (char s : expression) {
		if (s == '(') {
			st->push(s);
		}
		else if (s == ')') {
			if (st->isEmpty()) {
				return false;
			}
			st->pop();
		}
	}
	if (st->isEmpty())
		return true;
	return false;
}

// For flower brackets, square brackets and parenthesis
bool isBalancedComplex(Stack* st, string expression) {
	for (char s : expression) {
		if (s == '(' || s == '[' || s == '{') {
			st->push(s);
		}
		else if (s == ')' || s == ']' || s == '}') {
			if (st->isEmpty()) {
				return false;
			}
			char ret = st->pop();
			if (s == ')' && ret != '(')
				return false;
			else if (s == ']' && ret != '[')
				return false;
			else if (s == '}' && ret != '{')
				return false;
		}
	}
	if (st->isEmpty())
		return true;
	return false;
}

int main()
{
	Stack st;
	// string exp = "((a + b) * (c - d))";
	string exp = "{[a + b] - (c] + [d * 5])}}";
	// cout << "Is parenthesis balanced in expression : " << isBalanced(&st, exp) << endl;
	cout << "Is parenthesis balanced in expression : " << isBalancedComplex(&st, exp) << endl;
	return 0;
}
