/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int label;
    vector<int> req;
    
    Node(int label) {
        this->label = label;
    }
};

struct Graph {
    vector<Node*> jobs;
    int size;
    
    Graph(int n) {
        this->size = n;
        for (int i = 1; i <= n; i++) {
            jobs.push_back(new Node(i));
        }
    }
    
    void listJobByOrder() {
        vector<int> res;
        int j = -1;
        int cnt = size;
        bool visited[size] = {0};
        while (cnt > 0) {
            ++j;
            if (j >= size) {
                j -= size;
            }
            
            if (visited[j]) {
                continue;
            }
            
            int len = jobs[j]->req.size();
            if (len != 0) {
                bool skip_flag = 0;
                for (int i = 0; i < len; i++) {
                    if (!visited[jobs[j]->req[i] - 1]) {
                        skip_flag = 1;
                        break;
                    }
                }
                
                if (skip_flag) continue;
            }
            
            visited[j] = 1;
            res.push_back(jobs[j]->label);
            --cnt;
        }
        
        for (int i = 0; i < size; i ++) {
            cout << res[i] << " ";
        }
    }
};

int main()
{
    int n,m,u,v;
    cin >> n >> m;
    Graph gr(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        gr.jobs[v-1]->req.push_back(u);
    }

    gr.listJobByOrder();
    return 0;
}
