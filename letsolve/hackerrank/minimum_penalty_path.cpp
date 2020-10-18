#include <bits/stdc++.h>
#define int long long

using namespace std;

#include "../../library/debug.h"
#include "../../library/graph.h"
#include "../../library/undigraph.h"
#include "../../library/dfs_undigraph.h"

template<typename T>
class exp_graph : public dfs_undigraph<T>{
  public:
  using dfs_undigraph<T>::edges;
  using dfs_undigraph<T>::g;
  using dfs_undigraph<T>::n;
  using dfs_undigraph<T>::ignore;

  vector<T> d; //1e9
  vector<int> p;
  int INF = 10000000;
  bool isnegative_cycle = false;

  exp_graph(int _n) : dfs_undigraph<T>(_n) {}

  void dijkstra(int u){
    d.assign(n, INF); //1e9
    p.assign(n, -1);

    d[u] = 0;
    priority_queue< pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>> > q;
    q.push({0, u});
    while(!q.empty()){            
      int v = q.top().second;
      T d_v = q.top().first;
      q.pop();

      if(d_v != d[v]) continue;

      for(auto edge_id: g[v]){
        auto &e = edges[edge_id];
        int to = e.from ^ e.to ^ v;
        if((d[v]|e.cost) < d[to]){
          d[to] = (d[v]|e.cost);
          p[to] = v;
          q.push({d[to], to});
        }
      }
    }
  }
};



vector<string> split_string(string);

// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    exp_graph<int> g(10001);
    for(int i = 0; i < (int) edges.size(); i++){
        g.add(--edges[i][0], --edges[i][1], edges[i][2]);
    }
    g.dijkstra(--A);
    int ans = 0;
    if(g.d[--B] == 10000000) return -1;
    return g.d[B];
}

int32_t main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B);

    cout << result << "\n";


    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
