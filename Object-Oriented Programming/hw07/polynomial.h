/*
Kenneth Huynh
CS1124
hw07 header

*/


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

namespace Polynomial {
	struct Node {
		Node(int data = 0, Node* link = nullptr);
		int data;
		Node* link;
	};

	void listInsertHead(int entry, Node*& headPtr);

	class Polynomial {
		Node* headPtr;
		int degree;
	public:
		Polynomial(std::vector<int> coeff);
		Polynomial(const Polynomial& rhs);
		~Polynomial();
		Polynomial& operator=(const Polynomial rhs);
		Polynomial& operator+=(const Polynomial& rhs);
		Node* getHead() const;
		int getDegree() const;
		void setDegree(int num);
		int evaluate(int num);

		
	};

	void listInsertAfter(int entry, Node* previousPtr);
	Node* listFindLast(Node* headPtr);
	Polynomial operator+(Polynomial left, const Polynomial& right);
	bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
	std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);
	void listClear(Node*& headPtr);
}

#endif