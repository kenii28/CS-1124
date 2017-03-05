/*
Kenneth Huynh
CS 1124
Rec07

This program performs the tasks in for rec07.
*/

#include <vector>
#include <iostream>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(const unsigned num)
		: numberOfPages(num) {}

	virtual void displayNumPages() const = 0; //{ cout << numberOfPages; }
protected:
private:
	unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(const unsigned num)
		: PrintedMaterial(num) {}

	void displayNumPages() const
	{
		cout << "Magazine";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(const unsigned num)
		: PrintedMaterial(num) {}

	void displayNumPages() const
	{
		cout << "Book";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(const unsigned num, const unsigned numIndexPages)
		: Book(num), numOfIndexPages(numIndexPages) {}

	void displayNumPages() const
	{
		PrintedMaterial::displayNumPages();
		cout << "Number of Index Pages: "<< numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(const unsigned num)
		: Book(num) {}

	void displayNumPages() const
	{
		cout << "Novel";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm)
{
	pm.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(234,23);
	Novel n(324);
	Magazine m(345);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();
	
	cout << "\n=========\n";


	PrintedMaterial* pmPtr;
	pmPtr = &t;

	pmPtr->displayNumPages();

	cout << "\n===========\n";

	displayNumberOfPages(t);
	displayNumberOfPages(n);
	displayNumberOfPages(m);

	cout << "\n=============\n";

	vector<PrintedMaterial*> vecpm;

	vecpm.push_back(&t);
	vecpm.push_back(&n);
	vecpm.push_back(&m);

	for (size_t index = 0; index < vecpm.size(); ++index)
	{
		vecpm[index]->displayNumPages();
	}

	system("pause");
}
