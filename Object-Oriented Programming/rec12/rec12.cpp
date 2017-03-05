#include <cstdlib>// To allow NULL if no other includes
#include <iostream>
using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

Node* findVal(Node* headPtr, int val) {
	Node* temp = headPtr;
	while (temp != nullptr) {
		if (temp->data == val) {
			return temp;
		}
		temp = temp->link;
	}
	return nullptr;
}

Node* listFindLast(Node* p) {
	if (p)
		while (p->link) p = p->link;
	return p;
}

void spliceIn(Node* toSplice, Node* place) {
	Node* temp = place->link;
	Node* end = listFindLast(toSplice);
	end->link = temp;
	place->link = toSplice;
}

void displayList(Node* headPtr) {
	while (headPtr != nullptr) {
		cout << headPtr->data << " ";
		headPtr = headPtr->link;
	}
	cout << endl;
}

Node* check(Node* toCheck, Node* target) {
	Node* temp = toCheck;
	Node* temp2 = target;
	Node* match = nullptr;
	bool check = false;
	
	while (temp2 != nullptr) {
		if (temp2->data == temp->data) {
			match = temp2;
			while (temp2->data == temp->data) {
				temp2 = temp2->link;
				temp = temp->link;
				if (temp == nullptr) {
					return match;
				}
				else if (temp2 == nullptr) {
					return nullptr;
				}
				else if (temp2->data != temp->data) {
					temp2 = match->link;
					temp = toCheck;
					match = nullptr;
				}
			}

		}
		temp2 = temp2->link;
	}
	return nullptr;
}

void displayCheck(Node* result, Node* toCheck){
	cout << "Attempt match: ";
	displayList(toCheck);
	if (result == nullptr) {
		cout << "Failed to match\n";
	}
	else {
		displayList(result);
	}
}
int main() {
	Node* headPtr = nullptr; 
	listInsertHead(1, headPtr);
	listInsertHead(9, headPtr);
	listInsertHead(7, headPtr);
	listInsertHead(5, headPtr);
	Node* headSplice = nullptr;
	listInsertHead(2, headSplice);
	listInsertHead(3, headSplice);
	listInsertHead(6, headSplice);
	cout << "Part One:\n\nL1: ";
	displayList(headPtr);
	cout << "L2: ";
	displayList(headSplice);
	cout << "Target: ";
	Node* place = findVal(headPtr, 7);
	displayList(place);
	cout << "Splicing L2 at target in L1\nL1: ";
	spliceIn(headSplice, place);
	displayList(headPtr);
	Node* list2 = place->link;
	cout << "L2: ";
	displayList(list2);
	cout << "====================\n\nPart two:\n\nTarget: ";
	Node* headPtr2 = nullptr;
	listInsertHead(6, headPtr2);
	listInsertHead(5, headPtr2);
	listInsertHead(4, headPtr2);
	listInsertHead(2, headPtr2);
	listInsertHead(3, headPtr2);
	listInsertHead(2, headPtr2);
	listInsertHead(3, headPtr2);
	listInsertHead(2, headPtr2);
	listInsertHead(1, headPtr2);
	displayList(headPtr2);
	Node* attempt1 = nullptr;
	listInsertHead(1, attempt1);
	Node* result1 = check(attempt1, headPtr2);
	displayCheck(result1, attempt1);
	Node* attempt2 = nullptr;
	listInsertHead(9, attempt2);
	listInsertHead(3, attempt2);
	Node* result2 = check(attempt2, headPtr2);
	displayCheck(result2, attempt2);
	Node* attempt3 = nullptr;
	listInsertHead(3, attempt3);
	listInsertHead(2, attempt3);
	Node* result3 = check(attempt3, headPtr2);
	displayCheck(result3, attempt3);
	Node* attempt4 = nullptr;
	listInsertHead(6, attempt4);
	listInsertHead(5, attempt4);
	listInsertHead(4, attempt4);
	listInsertHead(2, attempt4);
	Node* result4 = check(attempt4, headPtr2);
	displayCheck(result4, attempt4);
	Node* attempt5 = nullptr;
	listInsertHead(4, attempt5);
	listInsertHead(2, attempt5);
	listInsertHead(3, attempt5);
	listInsertHead(2, attempt5);
	Node* result5 = check(attempt5, headPtr2);
	displayCheck(result5, attempt5);
	Node* attempt6 = nullptr;
	listInsertHead(7, attempt6);
	listInsertHead(6, attempt6);
	listInsertHead(5, attempt6);
	Node* result6 = check(attempt6, headPtr2);
	displayCheck(result6, attempt6);


	system("pause");

}