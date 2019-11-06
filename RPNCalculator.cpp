#include "RPNCalculator.h"
#include <iostream>

using namespace std;


// Contructor
RPNCalculator::RPNCalculator() {
	currentPlate = nullptr;

}

//Destructor
RPNCalculator::~RPNCalculator() {

}

//return value of currentPlate while dealigating old currentPlate
double RPNCalculator::stackPop() {
	double value = currentPlate->num;

	plate* shatteredplate = currentPlate;

	currentPlate = currentPlate->nxtPlate;

	delete shatteredplate;

	return value;

}


//Push to the top of the stack
void RPNCalculator::stackPush(double Num) {
	plate* PLATE = new plate();

	PLATE->num = Num;
	PLATE->nxtPlate = currentPlate;
	currentPlate = PLATE;

}

bool RPNCalculator::isEmpty() {
	return currentPlate == nullptr;
}

//peek at the top of the stack
double RPNCalculator::peek() {
	return currentPlate->num;
}

//Add
double RPNCalculator::add() {
	if (!isEmpty()) {
		double value1 = stackPop();
		if (!isEmpty()) {
			double value2 = stackPop();
			double value3;

			//MATH
			value3 = value2 + value1;

			stackPush(value3);

			return value3;
		}
		//if first value out and no second value
		else {
			stackPush(value1);
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//Subtract
double RPNCalculator::subtract() {
	if (!isEmpty()) {
		double value1 = stackPop();
		if (!isEmpty()) {
			double value2 = stackPop();
			double value3;

			//MATH
			value3 = value2 - value1;

			stackPush(value3);

			return value3;
		}
		//if first value out and no second value
		else {
			stackPush(value1);
			return 0;
		}
	}
	else
	{
		return 0;
	}
};

//Multiply
double RPNCalculator::multiply() {
	if (!isEmpty()) {
		double value1 = stackPop();
		if (!isEmpty()) {
			double value2 = stackPop();
			double value3;

			//MATH
			value3 = value2 * value1;

			stackPush(value3);

			return value3;
		}
		//if first value out and no second value
		else {
			stackPush(value1);
			return 0;
		}
	}
	else
	{
		return 0;
	}
};

//Divide
double RPNCalculator::divide() {
	if (!isEmpty()) {
		double value1 = stackPop();
		if (!isEmpty()) {
			double value2 = stackPop();
			double value3;

			//MATH
			value3 = value2 / value1;

			stackPush(value3);
			return value3;
		}
		//if first value out and no second value
		else {
			stackPush(value1);
			return 0;
		}
	}
	else
	{
		return 0;
	}
};

//Power
double RPNCalculator::power() {
	if (!isEmpty()) {
		double value1 = stackPop();
		if (!isEmpty()) {
			double value2 = stackPop();
			double value3;
			double tempValue2;

			tempValue2 = value2;
			value3 = value2;

			//if power to 0
			if (value1 == 0) {
				value3 = 1;

				stackPush(value3);
				return value3;
			}

			//loop until answer
			for (int i = 1; i < value1; i++)
			{
				//MATH
				value3 = tempValue2 * value3;
			}

			stackPush(value3);
			return value3;
		}
		else {
			stackPush(value1);
			return 0;
		}
	}
	else
	{
		return 0;
	}
}