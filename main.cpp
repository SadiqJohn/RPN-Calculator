#include "RPNCalculator.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	RPNCalculator* calc = new RPNCalculator();

	cout << "Welcome to the RPN Calculator! \n" <<
		"Enter a number following a second number \n" <<
		"Then enter a sign to get a value \n" <<
		"Enter q to quit \n" <<
		"----------------------------------------- \n";

	string input;
	double value;

	do
	{
		cout << "\n >>";
		cin >> input;


		switch (input.at(0))
		{
		case '+':
			cout << calc->add();
			break;

		case '-':
			cout << calc->subtract();
			break;

		case '*':
			cout << calc->multiply();
			break;

		case '/':
			cout << calc->divide();
			break;

		case '^':
			cout << calc->power();
			break;

		default:
			try
			{
				value = stod(input);
				calc->stackPush(value);
			}
			catch (invalid_argument)
			{
				cout << "Invalid input \n";
			}
			break;
		}

		//QUIT
	} while (input != "q");

	return 0;
};