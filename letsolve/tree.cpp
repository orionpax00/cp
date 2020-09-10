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
class forest : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
	vector<int> outdeg;

  forest(int _n) : graph<T>(_n) {
		outdeg.resize(n);
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
		outdeg[from]++;
   // g[to].push_back(id); assuming directed edge | just for this question
    edges.push_back({from, to, cost});
    return id;
  }

	int leaf_node_sum(){
		int ans = 0;
		for(int i = 0 ; i < n; i++){
			if(outdeg[i] == 0) ans += i;
		}

		return ans;
	}


};

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
  
	forest<int> tree(n);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v; // u v should be zero base indexed
		tree.add(u, v);
	}
	
	cout <<	tree.leaf_node_sum();

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
