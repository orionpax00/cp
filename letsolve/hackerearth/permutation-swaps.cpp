#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> visited;
vector<int> par;
vector<int> goal;
vector<int> A;
vector<int> B;

void dfs(int u){
	visited[u] = 1;	
	A.push_back(par[u]);
  B.push_back(goal[u]);
	for(int v: g[u]){
		if(!visited[v]) dfs(v);
	}

}


void solve(){
	g.clear();
	visited.clear();
	goal.clear();
	par.clear();
	int n, m; cin >> n >> m;
	g.resize(n, vector<int>());
	visited.resize(n);
	goal.resize(n);
	par.resize(n);
	
	for(int i = 0 ; i < n; i++) cin >> par[i];
	for(int i = 0 ; i < n; i++){
		cin >> goal[i];
	}


	for(int i = 0; i < m; i++){
		int a, b; 
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);	
	}

	bool ok = true;

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			A.clear(); B.clear();
			dfs(i);
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());
			if(A != B) ok = false;
		} 
	}



	cout << (ok ? "YES\n" : "NO\n") ;

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}

