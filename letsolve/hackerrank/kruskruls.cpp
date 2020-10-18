#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


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

template <typename T>
class dfs_undigraph : public undigraph<T> {
  public:
  using undigraph<T>::edges;
  using undigraph<T>::g;
  using undigraph<T>::n;
  using undigraph<T>::ignore;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<int> min_depth;
  vector<T> dist;
  vector<int> was;
  int attempt;

  dfs_undigraph(int _n) : undigraph<T>(_n) {
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
    min_depth = vector<int>(n, -1);
    dist = vector<T>(n);
    was = vector<int>(n, -1);
    attempt = 0;
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
    min_depth.clear();
    dist.clear();
    was.clear();
  }

  private:
  void do_dfs(int v) {
    was[v] = attempt;
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    min_depth[v] = depth[v];
    for (int id : g[v]) {
      if (id == pe[v] || (ignore != nullptr && ignore(id))) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      if (was[to] == attempt) {
        min_depth[v] = min(min_depth[v], depth[to]);
        continue;
      }
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
      min_depth[v] = min(min_depth[v], min_depth[to]);
    }
    end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    ++attempt;
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

  public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};


template<typename T>
class exp_graph : public dfs_undigraph<T>{
  public:
  using dfs_undigraph<T>::edges;
  using dfs_undigraph<T>::g;
  using dfs_undigraph<T>::n;
	using dfs_undigraph<T>::pv;
	using dfs_undigraph<T>::pe;
	using dfs_undigraph<T>::depth;
	using dfs_undigraph<T>::min_depth;
  using dfs_undigraph<T>::ignore;

  vector<T> d; //1e9
  vector<int> p;
  vector<int> neg_cycle;
  vector<int> mst_edges;
  vector<int> cutpoints;
  vector<bool> bridges;
  int INF = 1000000000;
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
        if(d[e.from] < INF){
          int to = e.from ^ e.to ^ i;
          if(d[to] > d[e.from] + e.cost){
            d[to] = max(-INF, d[e.from] + e.cost);
            p[to] = e.from;
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

	// call it after dfs_all()
  void find_bridges(){
    bridges.resize(edges.size(), false);
    for(int i = 0 ; i < n; i++){
      if(pv[i] != -1 && min_depth[i] == depth[i]) bridges[pe[i]] = true;
    }  
  }
	//call it after dfs_all
  void find_cutpoints(){
    cutpoints.resize(n);
    for(int i = 0 ; i < n; i++){
      if(pv[i] != -1 && min_depth[i] >= depth[pv[i]]) cutpoints[pv[i]] = true;
    }

    vector<int> children(n, 0);
    for(int i =0; i < n; i++){
      if(pv[i] != -1){
        children[pv[i]]++;
      }
    }

    for(int i =0; i < n; i++){
      if(pv[i] == -1 && children[i] < 2){
        cutpoints[i] = false;
      }
    }
  }
   

  void find_mst(){
    vector<int> _order(edges.size());
    iota(_order.begin(), _order.end(), 0);
    sort(_order.begin(), _order.end(), [&](int a, int b){
      return edges[a].cost < edges[b].cost;
    });

    dsu d(n);
    for(int id : _order){
      auto &e = edges[id];
      if(d.find(e.from) != d.find(e.to)){
        d.unite(e.from, e.to);
        mst_edges.push_back(id);
      }
    }
  }
};



// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
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


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

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
