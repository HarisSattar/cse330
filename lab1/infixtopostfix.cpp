
/********************************************************************************
 * Haris Sattar
 * intfixtopostfix.cpp
 * 1/14/16
 * This program converts equations from infix notation to postfix notation by
 * using a stack and determining the precedence of operators to control the
 * output of the equation from the stack.
 ********************************************************************************/

#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

int prec(char op)
{
	if (op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return 0;
} //prec

int main()
{
	stack<char> operators;
	char input;

	while (cin >> input) {
		if (isalnum(input))
			cout << input << " ";
		else {
			if (input == '(')
				operators.push(input);
			else if (input == ')') {
				while (!operators.empty() && operators.top() != '(') {
					cout << operators.top() << " ";
					operators.pop();
				}
				if (!operators.empty())
					operators.pop();
				else
					cout << "error" << endl;
			} else if (input == '+' || input == '-' || input == '*' || input == '/') {
				if (operators.empty() || prec(operators.top()) < prec(input))
					operators.push(input);
				else {
					while (!operators.empty() && prec(operators.top()) >= prec(input)) {
						cout << operators.top() << " ";
						operators.pop();
					}
					operators.push(input);
				}
			}
		}
	}
	while (!operators.empty()) {
		cout << operators.top() << " ";
		operators.pop();
	}
	cout << endl;
} //main

