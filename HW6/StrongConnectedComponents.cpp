#include <iostream>
#include <vector>

using namespace std;

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
};

int main()
{
    Graph graph;
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        graph.addNode(new Node(i));
    }
    
    int k1, k2;
    for (int i = 0; i < m; i++) {
        cin >> k1 >> k2;
        graph.nodes[k1-1]->addConnect(graph.nodes[k2-1]);
        graph.nodes[k2-1]->addConnect(graph.nodes[k1-1]);
    }

    cout << graph.strongConnectedComponents();
    return 0;
}