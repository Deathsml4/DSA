/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w; // u va v la 2 dinh, w la trong so
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    
    bool operator > (Edge other) {
        if (this->w > other.w) {
            return 1;
        }
        
        else return 0;
    }
    
    bool operator < (Edge other) {
        if (this->w < other.w) {
            return 1;
        }
        
        else return 0;
    }
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
}dsu;

struct Graph {
    vector<Edge> edges;
    int vertex_num;
    
    Graph(int n) {
        this->vertex_num = n;
    }
    
    void sortByWeight() {
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (edges[i] > edges[j]) {
                    swap(edges[i], edges[j]);
                }
            }
        }
    }
    
    void smallestCostConnect() {
        int cost = 0;
        sortByWeight();
        vector<Edge> res;
        bool visited[vertex_num] = {0};
        bool edge_visited[vertex_num][vertex_num] = {0};
        int n = edges.size();
        dsu.init(vertex_num);
        for (int i = 0; i < n; i++) {
            int v1, v2;
            v1 = edges[i].u;
            v2 = edges[i].v;
            /*if (visited[v1-1] && visited[v2-1]) {
                for (int j = 0; j < vertex_num; j++) {
                    if (visited[j]) {
                        if (edge_visited[v1-1][j] && edge_visited[v2-1][j]) {
                            continue;
                        }
                    }
                }
            }*/
            if (!dsu.join(v1, v2)) {
                continue;
            }
            
            
            visited[v1-1] = 1;
            visited[v2-1] = 1;
            edge_visited[v1-1][v2-1] = 1;
            edge_visited[v2-1][v1-1] = 1;
            res.push_back(edges[i]);
            cost += edges[i].w;
        }
        
        cout << cost;
        for (int i = 0 ; i < res.size(); i++) {
            cout << endl << res[i].u << " " << res[i].v << " " << res[i].w;
        }
    }
};

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    Graph gr(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        gr.edges.push_back(Edge(u, v, w));
    }

    gr.smallestCostConnect();
    
    return 0;
}
