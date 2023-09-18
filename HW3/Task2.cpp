#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

struct List {
	Node* head;
	List() {
		head == NULL;
	}
	void insert(int p, int x) {
		Node* newNode = new Node(x);
		Node* q = head;
		if (head == NULL) {
			head = newNode;
			return;
		}
		
		for (int i = 0 ; q->next != NULL ; i++) {
			if (p-1 == i) {
				break;
			}
			q = q->next;
		}
		
		newNode->next = q->next;
		q->next = newNode;
	}
	void _delete(int p) {
		Node* q = head;
		if (head == NULL) return;
		if (head->next == NULL) {
			delete q;
			head = NULL;
		}
		for (int i = 0 ; q->next != NULL; i++) {
			if (p-1 == i) {
				break;
			}
			q = q->next;
		}
		Node* deletingNode = q->next;
		q->next = deletingNode->next;
		delete deletingNode;
	}
	void print() {
		for (Node* p = head ; p != NULL ; p = p->next) {
			cout << p->data << " ";
		}
	}
};

int main() {
	List list;
	int n;
	cin >> n;
	string s;
	int p,x;
	for (int i = 0 ; i < n ; i++) {
		cin >> s;
		if (s == "insert") {
			cin >> p >> x;
			list.insert(p,x);
		}
		else {
			cin >> p;
			list._delete(p);
		}
		//getline(cin,s);
	}
	list.print();
	return 0;
}
