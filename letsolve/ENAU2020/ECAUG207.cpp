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
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
	vector<int> visited;
  undigraph(int _n) : graph<T>(_n) {
		visited.resize(n);
	}


  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
	
	dfs(int v){
		visited[v] = true;
	}

};




int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
