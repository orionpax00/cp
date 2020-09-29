#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> g;
vector<int> indegree;
vector<int> visited;
vector<int> depth;

void dfs(int v){
	visited[v] = 1;
	for(int u : g[v]){
		depth[u] = max(depth[u], depth[v] + 1);
		--indegree[u];
		if(indegree[u] == 0)
			dfs(u);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
  g.resize(n, vector<int>()); visited.resize(n); indegree.resize(n); depth.resize(n);

	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		indegree[b]++;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i] && indegree[i] == 0){
			dfs(i);
		}
	}

	cout << *max_element(depth.begin(), depth.end());


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
