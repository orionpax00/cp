#include <bits/stdc++.h>
#define int long long

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
	vector<int> indegree;

  digraph(int _n) : graph<T>(_n) {
		indegree.resize(n);
  }

  int add(int from, int to, T cost = 1) {
///		cerr << "---" << from << " " << to <<"\n";
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
		indegree[to]++;
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
	using digraph<T>::indegree;

  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;

	int mlp = INT_MIN;
	int auxmlp = 0;


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
   // pv = vector<int>(n, -1);
   // pe = vector<int>(n, -1);
//    order.clear();
  //  pos = vector<int>(n, -1);
  //  end = vector<int>(n, -1);
   // sz = vector<int>(n, 0);
    //root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
   // dist = vector<T>(n);
  }

  private:
  void do_dfs(int v) {
   // pos[v] = (int) order.size();
	//    order.push_back(v);
   // sz[v] = 1;
    for (int id : g[v]) {
				
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      // well, this is controversial...
      //if (depth[to] != -1) {
       // continue;
     // }

			depth[to] = depth[v] + 1;
     // dist[to] = dist[v] + e.cost;
      //pv[to] = v;
     // pe[to] = id;
     // root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      //sz[v] += sz[to];
    }
		
   // end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
		depth[v] = 0;
   // dist[v] = T{};
   // root[v] = v;
    //pv[v] = pe[v] = -1;
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


  void dfs_all() {
    init();
    vector<int> roots;
    for (int v : indegree) {
//        roots.push_back(v);
//				depth.clear();
        do_dfs_from(v);
				int m_ = *max_element(depth.begin(), depth.end());
				mlp = max(mlp, m_);
    }
    //assert((int) order.size() == n);
   // return roots;
  }
};

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m; 
  dfs_digraph<int> g(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; g.add(--a,--b);}

	g.dfs_all();
	cout << g.mlp + 1; 


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
