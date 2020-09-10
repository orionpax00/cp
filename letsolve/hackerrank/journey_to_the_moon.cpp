#include <bits/stdc++.h>
using namespace std;


class Graph{
  public:
  vector< vector<int>> g;
  vector<bool> visited;
  vector<int> count;
  int as_count = 0;
  int n;

  Graph(int _n){
    g.resize(_n+1, vector<int>());
    visited.resize(_n+1);
    n = _n;
  }

  void add(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void dfs(int u){
    visited[u] = true;
    as_count++;
    for(int v : g[u]){
      if(!visited[v]){
        dfs(v);
      }
    }
  }

  void dfs_all(){
    for(int i = 0; i< n; i++){
      if(!visited[i]){
        as_count = 0;
        dfs(i);
        count.push_back(as_count);
      }
    }
  }

};
// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> a) {
  Graph g(n);
  for(auto x : a) g.add(x[0], x[1]);

  g.dfs_all();
  long long ans = 0;
  long long total = 0;
  vector<int> revpref(n + 1);
  for(int i = (int)g.count.size(); i >= 0; i--){
    revpref[i] = revpref[i + 1] + g.count[i];
  }

  for(int i = 0 ; i < (int)g.count.size(); i++){
    ans +=  g.count[i] * revpref[i+1];
    total += g.count[i];
  }

  if(n - total > 0) {
    long long t = n - total;
    for(int x : g.count) ans += t * x;

    ans += (t*(t-1))/2;
  }

  return ans;
}

int main(){

	int n, m; cin >> n >> m;
	vector<vector<int>> v(m, vector<int>(2));

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[i] = {a, b};
	}

	cout << journeyToMoon(n, v);


	return 0;
}



