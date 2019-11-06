#pragma once

class RPNCalculator {
private:

	// set num , set plate to point to next plate
	struct plate {
		double num;
		plate* nxtPlate;
	};

	plate* currentPlate;

	//standard stack operations
	double stackPop();
	bool isEmpty();
	double peek();

public:

	// Contructor
	RPNCalculator();

	//Destructor
	~RPNCalculator();

	//Pusher
	void stackPush(double Num);

	//Add
	double add();

	//Subtract
	double subtract();

	//Multiply
	double multiply();

	//Divide
	double divide();

	//Power
	double power();
};