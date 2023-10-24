#include <iostream>
#include <vector>
//#include <list>

const int MAX_QUEUE = 100;

using namespace std;
class Queue {
public:
    int store[MAX_QUEUE];
    int i,j;
    
    Queue() {
        int i = 0;
        int j = 0;
    }
    
    void push(int k) {
        if (j == MAX_QUEUE) {
            j = 0;
        }
        
        if (j >= i - 1 && i != 0) {
            cout << "Queue is fulled!\n";
            return;
        }
        
        store[j++] = k;
    }
    
    int pop() {
        if (i != j) {
            cout << "Queue is empty!\n";
            return -1;
        }
        
        int tmp = store[i];
        store[i++] = 0;
        return tmp;
    }
};

class Node {
public:
    int label;
    vector<Node*> connect;
    
    Node(int label) {
        this->label = label;
    }
    
    void addConnect(Node* node) {
        this->connect.push_back(node);
    }
};

class Graph{
public:
    vector<Node*> nodes;
    
    Graph() {}
    
    void addNode(Node* node) {
        nodes.push_back(node);
    }
    
    void foo(bool* visited, Node* node) {
        int n = node->connect.size();
        for (int i = 0; i < n; i++) {
            int x = node->connect[i]->label - 1;
            if (visited[x]) continue;
            
            visited[x] = 1;
            foo(visited, node->connect[i]);
        }
    }
    
    int strongConnectedComponents() {
        int n = nodes.size();
        bool visited[n] = {0};
        int cnt = 0;
        for (int i =0; i < n; i++) {
            if (visited[i]) continue;
            cnt ++;
            visited[i] = 1;
            foo(visited, nodes[i]);
        }
        
        return cnt;
    }
    
    int shortestPath(int from, int to) {
        int n = nodes.size();
        bool visited[n] = {0};
        int path[n] = {n};
        path[from - 1] = 0;
        visited[from - 1] = 0;
        
        Queue queue;
        queue.i = 0;
        queue.j = 0;
        Node* p;
        Node* q = nodes[from - 1];
        for (int h = 0; h < q->connect.size(); h++) {
            p = q->connect[h];
            if (visited[p->label - 1]) {
                continue;
        	}
            
            visited[p->label - 1] = 1;
            path[p->label - 1] = 1 + path[q->label - 1];
            queue.push(p->label);
            if (p->label == to) {
                return path[p->label - 1];
            }
        }
        cerr <<  "Step1\n";
        //bool allVisited = 0;
        int k = queue.i;
        //int cnt = 1;
        while (k <= queue.j - 1) {
        	//cerr << cnt++ << endl;
        	//cerr << k;
            q = nodes[queue.store[k] - 1];
            //cerr << "A";
            for (int h = 0; h < q->connect.size(); h++) {
            	//cerr << cnt++ << endl;
                p = q->connect[h];
                if (visited[p->label - 1]) {
                    continue;
                }
                //cerr << "B";
                
                visited[p->label - 1] = 1;
                path[p->label - 1] = 1 + path[q->label - 1];
                queue.push(p->label);
                if (p->label == to) {
                    return path[p->label - 1];
                }
            }
            //cerr << "C";
            k++;
            //if (k >= MAX_QUEUE) k = 0;
        }
        
        return -1;
    }
};

int main()
{
    Graph graph;
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        graph.addNode(new Node(i));
    }
    
    int k1, k2;
    for (int i = 0; i < m; i++) {
        cin >> k1 >> k2;
        graph.nodes[k1-1]->addConnect(graph.nodes[k2-1]);
        graph.nodes[k2-1]->addConnect(graph.nodes[k1-1]);
    }

    cout << graph.shortestPath(x, y);
    return 0;
}
