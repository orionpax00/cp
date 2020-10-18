#include <bits/stdc++.h>
using namespace std;

#include "../dsu.h"
#include "../graph.h"
#include "../undigraph.h"
#include "../dfs_undigraph.h"
#include "../explore_undigraph.h"

vector<string> split_string(string);

int krus(int n, vector<vector<int>> edges, int start) {
    exp_graph<int> g(n);
    for(int i = 0; i < (int) edges.size(); i++){
        g.add(--edges[i][0], --edges[i][1], edges[i][2]);
    }

    g.find_mst();

    int ans = 0;
    for(int x : g.mst_edges){
        ans += g.edges[x].cost;
    }

    return ans;
}


int32_t main()
{

    //test kruskrul''s
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(auto& x : edges) cin >> x[0] >> x[1] >> x[2];
    int start; cin >> start;
    int result = krus(n, edges, start);
    if(result == 15) cout << "Kruskruls is working....\n";
    else "Kruskruls is broken\n";


    //test Dijkstra
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for(auto& x : edges) cin >> x[0] >> x[1] >> x[2];
    int start; cin >> start;
    int result = krus(n, edges, start);
    if(result == 15) cout << "Kruskruls is working....\n";
    else "Kruskruls is broken\n";


    return 0;
}

/*
TEST CASE FOR KRUSKRUL'S
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1
*/