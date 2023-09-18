#include <iostream> 

using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node(int data, Node* n = NULL) :data(data),next(n) {
		
	}
};

class Queue {
public:
	Node* head;
	Node* tail;
	
	Queue(Node* h = NULL, Node* t = NULL) : head(h), tail(t) {
		
	}
	
	void push(int data) {
		Node* newNode = new Node(data);
		if (tail == NULL) {
			head = newNode;
			tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
	
	int pop() {
		Node* poppingNode = head;
		head = head->next;
		int _data = poppingNode->data;
		if (head == NULL) tail = NULL;
		delete poppingNode;
		return _data;
	}
	
	void print() {
		for (Node* p = head ; p != NULL ; p = p->next) {
			cout << p->data << " ";
		}
	}
	
};

class StackByQueues {
public:
	Queue q1;
	Queue q2;
	
	void print() {
		if (q1.head == NULL) q2.print();
		else q1.print();
	}
	
	void push(int data) {
		if (q1.head == NULL) {
			q1.push(data);
			q1.tail->next = q2.head;
			q2.head = NULL;
			q1.tail = q2.tail;
			q2.tail = NULL;
		}
		else {
			q2.push(data);
			q2.tail->next = q1.head;
			q1.head = NULL;
			q2.tail = q1.tail;
			q1.tail = NULL;
		}
	}
	
	int pop() {
		if (q1.head == NULL) {
			return q2.pop() ;
		}
		else return q1.pop() ;
	}
};

int main() {
	/*Queue queue;
	queue.push(11);
	queue.push(9);
	queue.push(15);
	queue.print();
	cout << endl;
	while (queue.head != NULL) {
		cout << queue.pop() << " ";
	}*/
	StackByQueues stk;
	int n,k;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> k;
		stk.push(k); 
	}
	
	stk.print();
	cout << endl;
	for (int i = 0 ; i < n ; i ++) {
		cout << stk.pop() << " ";
	}
	return 0;
}
