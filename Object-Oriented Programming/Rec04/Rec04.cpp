/*
Kenneth Huynh
CS 1124
Rec04

This program contains a sandwich class for Rec04.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sandwich
{
public:
	Sandwich(int numTomato = 2, int numCheese = 1, double amtMustard = .05, double amtMayo = 0.1)
		: tomato(numTomato), cheese(numCheese), mustard(amtMustard), mayo(amtMayo), bread(2) {}

	void display() const
	{
		cout << "Number of bread: " << bread << endl;
		cout << "Number of cheese: " << cheese << endl;
		cout << "Amount of mayo: " << mayo << endl;
		cout << "Amount of mustard: " << mustard << endl;
		cout << "Number of tomato: " << tomato << endl;
	}

	int getBread()
	{
		return bread;
	}

	int getCheese()
	{
		return cheese;
	}

	double getMayo()
	{
		return mayo;
	}

	double getMustard()
	{
		return mustard;
	}

	int getTomato()
	{
		return tomato;
	}

	void setCheese(int numCheese)
	{
		cheese = numCheese;
	}

	void setMayo(double amtMayo)
	{
		mayo = amtMayo;
	}

	void setMustard(double amtMustard)
	{
		mustard = amtMustard;
	}

	void setTomato(int numTomato)
	{
		tomato = numTomato;
	}
private:
	const int bread;
	int cheese;
	double mayo;
	double mustard;
	int tomato;
};

class SandwichTruck
{
public:
	void checkBeforeLeaving()
	{
		for (const Sandwich& sandwich : truck)
		{
			sandwich.display();
		}
	}
	
	void insertSandwich(const Sandwich& sandwich)
	{
		truck.push_back(sandwich);
	}
private:
	vector<Sandwich> truck;
};
int main()
{
	SandwichTruck truck;

	Sandwich sandwichOne;
	truck.insertSandwich(sandwichOne);

	Sandwich sandwichTwo;
	sandwichTwo.setMustard(0);
	truck.insertSandwich(sandwichTwo);

	Sandwich sandwichThree(2,2);
	truck.insertSandwich(sandwichThree);

	Sandwich sandwichFour;
	truck.insertSandwich(sandwichFour);

	truck.checkBeforeLeaving();
	double sandwichTwoMustard;
	sandwichTwoMustard = sandwichTwo.getMustard();
	cout << "The amount of mustard in sandwich 2 is: " << sandwichTwoMustard << endl;

	/*s.display();

	s.setCheese(4);
	s.setTomato(50);

	int numTomato;
	numTomato = s.getTomato();
	cout << numTomato << endl;

	s.display();*/
	system("pause");
}