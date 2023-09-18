#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data, Node* n = NULL, Node* p = NULL) {
		this->data = data;
		this->next = n;
		this->prev = p;
	}
};

struct DLList{
    Node* head;
    Node* tail;

    DLList(){
        head = NULL;
        tail = NULL;
    }

    void add(int data){
        if(head == NULL){
            head = tail = new Node(data, head, tail);
            return;
        }
        
        Node* p = head;
        for(; p != tail; p = p->next){
        }

        Node* newNode = new Node(data, NULL, NULL);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    int count_triplets(){
        int count = 0;
        for(Node* p = head; p->next->next != NULL; p = p->next){
            if(p->data + (p->next)->data + (p->next->next)->data == 0){
                count++;
            }
        }
        return count;
    }

    void print(){
        for(Node* p = head; p != NULL; p = p->next){
            cout << p->data <<  " ";
        }
        cout << endl;
    }
};

int main(){
    DLList ds;

    int n;
    cin >> n;
    int cnt(0);
    while(cnt < n){
        int x;
        cin >> x;
        ds.add(x);
        cnt++;
    }

    cout << ds.count_triplets() << endl;

    return 0;
}
