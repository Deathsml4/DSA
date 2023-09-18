#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data, Node* next) :data(data), next(next) {}
};

struct Stack{
    Node* head;

    Stack(){
        head = NULL;
    }

    Node* push(int x){
        if(head == NULL){
            head = new Node(x, head);
            return head;
        }
        
        Node* p = head;
        for(;p->next != NULL; p = p->next){}
        Node* newNode = new Node(x, NULL);
        newNode->next = p->next;
        p->next = newNode;
        return newNode;
    }

    void pop(){
        if(head == NULL){
            return ;
        }

        if(head->next == NULL){
            delete head;
            head = NULL;
            return ;
        }

        Node* p = head;
        for(; p->next->next != NULL; p = p->next){}
        delete p->next;
        p->next = NULL;

    }

    void print(){
        for(Node* p = head; p != NULL; p= p->next){
            cout << p->data << " ";
        }
        
        cout << endl;
    }
};

int main(){
    Stack stack;
    int n;
    cin >> n;
    int cnt(0);
    while(cnt < n){
        string s;
        cin >> s;
        int x;
        if(s == "push"){
            cin >> x;
            stack.push(x);
        }else {
            stack.pop();
        }

        cnt++;
    }

    stack.print();
}
