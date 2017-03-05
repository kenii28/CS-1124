/*
Kenneth Huynh
Recitation 14
Recursion
*/
#include <cstdlib>
#include <iostream>
#include <climits>


using namespace std;

void displayBinary(int num) {
	if (num < 2) {
		cout << num;
	}
	else {
		displayBinary(num / 2);
		cout << num % 2;
	}
}

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void displayList(Node* headPtr) {
	while (headPtr != nullptr) {
		cout << headPtr->data << " ";
		headPtr = headPtr->link;
	}
	cout << endl;
}

Node* addLists(Node* first, Node* second) {
	static Node* result = nullptr;
	if (first != nullptr) {
		addLists(first->link, second->link);
		int sum = first->data + second->data;
		listInsertHead(sum, result);
	}
	
	return result;

}

struct TNode {
	TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

int maxFn(TNode* root) {
	if (root == nullptr) return -1;
	static int max = INT_MIN;
	if (root->data > max) {
		max = root->data;
	}
	maxFn(root->left);
	maxFn(root->right);
	return max;
}

int sumASCII(char* start) {
	int sum = 0;
	if (start[0] != '\0') {
		sum += int(start[0]);
		sum += sumASCII(start + 1);
	}
	return sum;
}

int binarySearch(char target, char* string, int start, int end) {
	if (start > end) return -1;
	int mid = start + (end - start) / 2;
	if (target == string[mid]) {
		return mid;
	}
	else if (target > string[mid]) {
		return binarySearch(target, string, mid + 1, end);
	}
	else if (target < string[mid]) {
		return binarySearch(target, string, start, mid - 1);
	}
}

void f(int n) {
	if (n > 1) {
		cout << 'a';
		f(n / 2);
		cout << 'b';
		f(n / 2);
	}
	cout << 'c';
}

int a(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return a(y, x%y);
	}
}

int main() {
	/*displayBinary(8);
	cout << endl;
	displayBinary(7);
	cout << endl;
	displayBinary(13);
	cout << endl;*/

	/*Node* head1 = new Node(1);
	listInsertHead(9, head1);
	listInsertHead(7, head1);
	listInsertHead(5, head1);

	Node* head2 = new Node(1);
	listInsertHead(9, head2);
	listInsertHead(7, head2);
	listInsertHead(5, head2);

	displayList(head1);
	displayList(head2);
	Node* result = addLists(head1, head2);
	displayList(result);*/

	/*TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << maxFn(&f) << endl;*/

	/*char c[] = "I love C++";
	int sum = sumASCII(c);
	cout << sum;*/

	/*char c[] = "abcdefg";
	cout << binarySearch('z', c, 0, 7);*/

	/*f(1);
	cout << endl;
	f(2);
	cout << endl;
	f(3);
	cout << endl;
	f(4);
	cout << endl;
	f(5);
	cout << endl;
	f(6);
	cout << endl;
	f(7);
	cout << endl;
	f(8);
	cout << endl;
	f(9);
	cout << endl;
	f(10);
	cout << endl;
	f(11);
	cout << endl;
*/

	cout << a(6, 35);
	system("pause");
}