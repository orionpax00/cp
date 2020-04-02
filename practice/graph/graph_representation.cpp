// this is the cpp implementation of graph structures....

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    string startEdge;
    string endEdge;
};

class ClassEdge {
    
    public:
    
    string startEdge;
    string endEdge;
};


// OOPS BASED GRAPH STRUCTURE
class Graph {     
    public:
        int nv;
        vector < int > *adj;
        Graph(int nv);
        void addEdge( int u , int v);
        bool isReachable(int s, int e);
};

Graph::Graph(int nv){
    this->nv = nv;
    adj = new vector < int > [nv];
};

void Graph::addEdge( int u, int v){
    adj[u].push_back(v);
};


int main(){

    // DRIVER CODE FOR STRUCT REPRESENTATION
    Edge edge[100];

    edge[0].startEdge = "durgesh";
    edge[0].endEdge = "kuamr";

    edge[1].startEdge = "random";
    edge[1].endEdge = "ran";

    
    for(int i = 0 ; i < 2; i++){
        cout<<edge[i].startEdge<<endl;
    }

    ClassEdge cedge[100];

    cedge[0].startEdge = "durgesh";
    cedge[0].endEdge = "kuamr";

    cedge[1].startEdge = "random";
    cedge[1].endEdge = "ran";

    //DRIVER CODE FOR OOPS GRAPH
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    for (auto x : g.adj[0]){
    cout<<x<<"\n\n";}


}