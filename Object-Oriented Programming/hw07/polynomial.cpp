/*
Kenneth Huynh
CS1124
hw07 implementation

*/
#include <cstdlib> // To allow NULL if no other includes
#include "polynomial.h"

using namespace std;

namespace Polynomial{
	Node::Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}

	void listInsertHead(int entry, Node*& headPtr) {
		headPtr = new Node(entry, headPtr);
	}

	Polynomial::Polynomial(vector<int> coeff) : headPtr(nullptr), degree(coeff.size() - 1) {
		for (size_t i = 0; i < coeff.size(); i++) {
			listInsertHead(coeff[i], headPtr);
		}
	}

	Node* Polynomial::getHead() const { return headPtr; }
	int Polynomial::getDegree() const { return degree; }

	void listInsertAfter(int entry, Node* previousPtr) {
		// Create a new node.  Where are we putting it??
		Node* temp = new Node;
		// Place the new entry into the new node.
		temp->data = entry;
		// Make the new node point to the next node after previousPtr.
		temp->link = previousPtr->link;
		// Make previousPtr's node point to the new node.
		previousPtr->link = temp;
	}

	Node* listFindLast(Node* headPtr) {
		Node* p = headPtr;
		if (p != nullptr) {
			// The most important part of this function is the while condition.
			// Note that when the loop is over, p points to the last item.
			// If we had tested "while (p != NULL)" then p would be NULL!!!
			while (p->link != nullptr)
				p = p->link;
		}
		return p;
	}

	void Polynomial::setDegree(int num) {
		degree = num;
	}

	Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
		int degree1 = getDegree();
		int degree2 = rhs.getDegree();
		Node* temp1 = getHead();
		Node* temp2 = rhs.getHead();

		if (degree1 < degree2) {
			while (temp1 != nullptr) {
				temp1->data += temp2->data;
				temp1 = temp1->link;
				temp2 = temp2->link;
			}
			while (temp2 != nullptr) {
				listInsertAfter(temp2->data, listFindLast(headPtr));
			}
			setDegree(degree2);
		}
		else if (degree1 > degree2) {
			while (temp2 != nullptr) {
				temp1->data += temp2->data;
				temp1 = temp1->link;
				temp2 = temp2->link;
			}
		}
		else { // degrees are equal
			while (temp1 != nullptr) {
				temp1->data += temp2->data;
				temp1 = temp1->link;
				temp2 = temp2->link;
			}
		}
		return *this;
	}

	Polynomial operator+(Polynomial left, const Polynomial& right) {
		left += right;
		return left;
	}

	bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		if (lhs.getDegree() != rhs.getDegree()) {
			return false;
		}
		else {
			Node* temp1 = lhs.getHead();
			Node* temp2 = rhs.getHead();
			while (temp1 != nullptr){
				if (temp1->data == temp2->data) {
					while (temp1->data == temp2->data) {
						temp1 = temp1->link;
						temp2 = temp2->link;
						if (temp1 == nullptr) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
		return !(lhs == rhs);
	}

	std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial){
		Node* p = polynomial.getHead();
		int d = polynomial.getDegree();
		vector<int> temp;
		while (p != nullptr) {
			temp.push_back(p->data);
		}
		for (int i = d; i > -1; --i) {
			os << "+"<< temp[i] << "x^" << i;
		}

		return os;
	}

	int Polynomial::evaluate(int num) {
		Node* p = getHead();
		int power = 0;
		int answer = 0;
		while (p != nullptr) {
			answer += (num^power) * p->data;
		}
		return answer;
	}

	void listClear(Node*& headPtr) {
		// Declare a temporary variable to use to "walk down" the list.
		Node *p = headPtr;
		// We can clear headPtr now that we have our temporary pointing to
		// the head node.
		headPtr = nullptr;
		// Keep going so long as we have any nodes.
		while (p != nullptr) {
			// Remember where the next node is after the one we're about to delete
			Node *link = p->link;
			// Delete the current node.
			delete p;
			// Set the current pointer to the next node
			// that we were careful to remember.
			p = link;
		}
	}

	Polynomial::~Polynomial() {
		listClear(headPtr);
	}

	Polynomial::Polynomial(const Polynomial& rhs) {
		if (rhs.headPtr != nullptr) {
			Node* temp = rhs.headPtr;
			headPtr = new Node(rhs.headPtr->data);
			degree = rhs.degree;
			temp = temp->link;
		}
		else {
			headPtr = nullptr;
			degree = 0;
		}
	}

	Polynomial& Polynomial::operator=(const Polynomial rhs) {
		if (this != &rhs) {
			listClear(headPtr);
			if (rhs.headPtr == nullptr) {
				headPtr = nullptr;
				degree = 0;
			}
			else {
				Node* temp = rhs.headPtr;
				headPtr = new Node(rhs.headPtr->data);
				degree = rhs.degree;
				temp = temp->link;
			}
		}
	}

}
