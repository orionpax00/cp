#include <bits/stdc++.h>

using namespace std;

class Graph {     
    
    int nv;
    vector < int > *adj;
    void DFSUtil(int v, bool visited[]);

    public:
        
        Graph(int nv);
        void addEdge( int u , int v);
        bool isReachable(int s, int e);
        void DFS(int sv);
};

Graph::Graph(int nv){
    this->nv = nv;
    adj = new vector < int > [nv];
};

void Graph::addEdge( int u, int v){
    adj[u].push_back(v);
};

void Graph::DFSUtil(int sv , bool visited[]){
    visited[sv] = true;

    cout << sv << " ";

    vector < int > :: iterator i;
    for (i = adj[sv].begin(); i != adj[sv].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
     
};

void Graph::DFS(int sv){
    bool *visited = new bool[nv];
    for (int i = 0; i < nv; i++){
        visited[i] = false;
    }

    DFSUtil(sv, visited);
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
}