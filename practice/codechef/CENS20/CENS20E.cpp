#include <bits/stdc++.h>
#define int long long

using namespace std;

int MAXN = 200007;

vector<bool> visited(MAXN);
vector< vector<int> > g(MAXN, vector<int>());
vector<vector<int>> ans(MAXN, vector<int>(2));
vector<int> pa;

void dfs(int u){
	visited[u] = true;
	if(pa[u]&1) ans.back()[0]++;
	else ans.back()[1]++;
	for(int x : g[u]){
		if(!visited[x]) dfs(x);
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;

while(t--){
	g.clear();
	int n, m; cin >> n >> m;
	visited.assign(n+1,0);
	pa.assign(n+1,0);
	for(int i = 1; i < n + 1; i++){
		int w; cin >> w;
		pa[i] = __builtin_popcount(w)%2;
	}
	for(int i =0; i < m; i++){
		int f, t; cin >> f >> t;
		g[f].push_back(t); g[t].push_back(f);
	}

	for(int i = 1; i < n+1 ; i++){
		if(!visited[i]){
			ans.push_back({0, 0});
			dfs(i);
		}
		
	}

	int o = INT_MIN;
	int e = INT_MIN;
	for(auto x : ans){
		o = max(x[0] , o);
		e = max(x[1] , e);
	}

	
	int q; cin >> q;
	while(q--){
		int type, k; cin >>  type >> k;
		if(type == 1){
			if(k%2 == 0) cout << o << "\n";
			else cout << e << "\n";
		}else{
			if(k%2 == 0) cout << e <<"\n";
			else cout << o <<"\n";
		}
	}
	}
 
    

  return 0;
}
