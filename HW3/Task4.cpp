#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data, Node* next):data(data), next(next) {
	}
};

struct Queue{
    Node* head;
    
    Queue(){
        head = NULL;
    }

    int dequeue(){
        if(head == NULL || head->next == NULL){
            return 0;
        }

        Node* newHead = head->next;
        int data = head->data;
        Node* oldNode = head;
        delete oldNode;
        head = newHead;
        return data;

    }

    Node* queue(int x){
        if(head == NULL){
            head = new Node(x, head);
            return head;
        }

        Node* p = head;
        for(; p->next != NULL; p = p->next){}

        Node* newNode = new Node(x, NULL);

        newNode->next = p->next;
        p->next = newNode;

        return newNode;
        
    }


    void print(){
        for(Node* p = head; p != NULL; p = p->next){
            cout << p->data << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue queue;
    int n;
    cin >> n;
    int i = 0;
    while(i < n){
        string s;
        int x;
        cin >> s;
        if(s == "enqueue"){
            cin >> x;
            queue.queue(x);
        }else {
            queue.dequeue();
        }
        i++;
    }

    queue.print();
}
