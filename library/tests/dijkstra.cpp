#include <bits/stdc++.h>
//#define int long long
using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
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
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() const {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};


template <typename T>
class dfs_digraph : public digraph<T> {
  public:
  using digraph<T>::edges;
  using digraph<T>::g;
  using digraph<T>::n;
  using digraph<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

  dfs_digraph(int _n) : digraph<T>(_n) {
  }

  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      // well, this is controversial...
      if (depth[to] != -1) {
        continue;
      }
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

  public:
  int dfs_one_unsafe(int v) {
    // run init() before this
    // then run this with the required v's
    do_dfs_from(v);
    return v;
  }

  int dfs(int v) {
    init();
    do_dfs_from(v);
//    assert((int) order.size() == n);
    return v;
  }

  void dfs_many(const vector<int> &roots) {
    init();
    for (int v : roots) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
//    assert((int) order.size() == n);
  }

  vector<int> dfs_all() {
    init();
    vector<int> roots;
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        roots.push_back(v);
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
    return roots;
  }
};

template<typename T>
class explore_digraph : public dfs_digraph<T>{
  public:
  using dfs_digraph<T>::edges;
  using dfs_digraph<T>::g;
  using dfs_digraph<T>::n;
  using dfs_digraph<T>::ignore;

  vector<T> d; //1e9
  vector<int> p;
  vector<int> neg_cycle;
  int INF = 1000000000;
  bool isnegative_cycle = false;

  explore_digraph(int _n) : dfs_digraph<T>(_n) {}

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
        if(d[v] + e.cost < d[to]){
          d[to] = d[v] + e.cost;
          p[to] = v;
          q.push({d[to], to});
        }
      }
    }
  }

  void bellman_ford(int u){
    //init
    d.assign(n, INF); //1e9
    p.assign(n, -1);

    d[u] = 0;
    int x;
    for(int i = 0 ; i < n ; i++){
      x = -1;
      for(int j = 0; j < (int)edges.size(); j++){
        auto &e = edges[j];
				int from = e.from;
        if(d[from] < INF){
          int to = e.to;
					cerr << from << " " << to << "\n";
          if(d[to] > d[from] + e.cost){
            d[to] = max(-INF, d[from] + e.cost);
            p[to] = from;
            x = to;
          }
        }
      }
    }
		
    if(x != -1) isnegative_cycle = true;
    else{
      int y = x;
      for(int i = 0; i < n; i++) y = p[y];
      for(int curr = y; ;curr = p[curr]){
        neg_cycle.push_back(curr);
        if(curr == y && neg_cycle.size() > 1) break;
      }
      reverse(neg_cycle.begin(), neg_cycle.end());
    }
  }


  vector<int> restore_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
  }
  vector<int> toposort(){
    vector<int> deg(n, 0);
    for (int id = 0; id < (int) edges.size(); id++) deg[edges[id].to]++;

    vector<int> x;
    for (int i = 0; i < n; i++) 
      if (deg[i] == 0) 
        x.push_back(i);
      
    for (int ptr = 0; ptr < (int) x.size(); ptr++) {
      int i = x[ptr];
      //vector<int> temp; to_get lexo order
      for (int id : g[i]) {
        auto &e = edges[id];
        int to = e.to;
        if (--deg[to] == 0){ 
          //temp.push_back(to);
          x.push_back(to);
		}
      }
      //sort(temp.begin(), temp.end());
      //for(int y : temp) x.push_back(y); 
    }

    if ((int) x.size() != n) 
      return vector<int>();
    
    return x;
  }
  

};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, v; cin >> n >> v;
    explore_digraph<int> g(n);
    for(int i = 0 ; i < v ; i++){
        int u, v, w; cin >> u >> v >> w;
        g.add(u, v, w);
    }
  
//    g.dijkstra(0);
    g.bellman_ford(0);

    for(int x : g.d) cout << x << " ";
    cout << "\n" << "[Path] ";
    vector<int> path_ = g.restore_path(0, 5);
    for(int x : path_) cout << x << " ";

    return 0;
}
