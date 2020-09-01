#include <bits/stdc++.h>

using namespace std;


template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
    bool operator<(edge const& other) {
        return cost < other.cost;
    }
  };

  vector<edge> edges;
  vector< vector<int> > g;
  int n;

  function<bool(int)> ignore;

  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  undigraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

class dsu {
  public:
  vector<int> parent;
  vector<int> rank;

  int n;

  dsu(int _n){
    parent.resize(_n);
    iota(parent.begin(), parent.end(), 0);
    rank.resize(_n);
  }

  inline int find(int x){
    return (x == parent[x] ? x : (parent[x] = find(parent[x])));
  }

  void unite(int a, int b){
    a = find(a); b = find(b);

    if(a != b){
      if(rank[a] < rank[b]) swap(a,b);
      parent[b] = a;
      if(rank[a] == rank[b]) rank[a]++;
    }
  }
};


int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

  undigraph<int> g(g_nodes);
  dsu d(g_nodes);

  for(int i = 0 ; i < g_from.size(); i++){
    g.add(--g_from[i], --g_to[i], g_weight[i]);
  }
  
  sort(g.edges.begin(), g.edges.end());
  int cost = 0;
  for (auto e : g.edges) {
    if (d.find(e.from) != d.find(e.to)) {
        cost += e.cost;
        d.unite(e.from, e.to);
    }
  }
  return cost;
}
