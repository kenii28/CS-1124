/*
Kenneth Huynh
N18178828

Recitation 13

This program contains the code for rec 13.
*/

#include <cstdlib> // To allow NULL if no other includes
#include <iostream>

using namespace std;

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

class Sequence {
public:
	Sequence(Node* headPtr = nullptr, Node* current = nullptr) : headPtr(headPtr), current(current) {}
	Sequence(const Sequence& rhs) {
		if (rhs.headPtr != nullptr) {
			Node* temp = rhs.headPtr;
			headPtr = new Node(rhs.headPtr->data);
			current = headPtr;
			temp = temp->link;
			while (temp != nullptr) {
				add(temp->data);
			}
		}
		else {
			headPtr = nullptr;
			current = nullptr;
		}
	}

	~Sequence() {
		if (headPtr != nullptr && current != nullptr) {
			clear();
		}
	}

	Sequence& operator=(const Sequence& rhs) {
		if (this != &rhs) {
			clear();
			if (rhs.headPtr == nullptr) {
				headPtr = nullptr;
				current = nullptr;
			}
			else {
				Node* temp = rhs.headPtr;
				headPtr = new Node(rhs.headPtr->data);
				current = headPtr;
				temp = temp->link;
				while (temp != nullptr) {
					add(temp->data);
				}
			}
		}
		
	}
	bool valid() {
		if (current != nullptr) return true;
		else return false;
	}

	void add(int num) {
		if (valid()) {
			Node* toAdd = new Node(num, current->link);
			current->link = toAdd;
			current = current->link;
		}
		else {
			headPtr = new Node(num);
			current = headPtr;
		}
	}

	void remove() {
		if (valid()) {
			Node* temp = current->link;
			Node* tempHead = headPtr;
			if (tempHead == current) {
				delete current;
				headPtr = temp;
				current = temp;
				return;
			}
			while (tempHead->link != current) {
				tempHead = tempHead->link;
			}
			delete current;
			tempHead->link = temp;
		}
		else return;
	}

	int data() {
		if (valid()) {
			return current->data;
		}
	}

	void next() {
		if (valid()) {
			if (current->link != nullptr) {
				current = current->link;
			}
			else return;
		}
	}

	void clear() {
		reset();
		while (current != nullptr) {
			remove();
		}
	}

	void display(ostream& os, char separate = ' ') {
		Node* temp = headPtr;
		while (temp != nullptr) {
			os << temp->data << separate;
			temp = temp->link;
		}
		os << endl;
	}

	void reset() {
		current = headPtr;
	}

private:
	Node* headPtr;
	Node* current;
};

int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display(cout);
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 3; ++i) s.next();
	s.add(42);
	s.display(cout);
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display(cout);
	cout << "==========\n";
	s.clear();
	s.display(cout);
	cout << "==========\n";

	
	system("pause");
}