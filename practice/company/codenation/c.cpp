#include <bits/stdc++.h>
//#define int long long

using namespace std;

vector<int> val;
vector<vector<int>> g;
vector<int> visited;
vector<int> chunks;


void dfs(int v){
	visited[v] = 1;
	chunks[v] = val[v];
	for(int u : g[v]){
		if(!visited[u]) dfs(u);
	}
}


int solve(){

	bool isallz = true;
	for(int x : val) 
		if(x) isallz = false;

	if(isallz) return 0;

	dfs(0);

	int counter = 0;
	int n = chunks.size();
	for(int i = 0; i < n;){
		bool ok = false;
		while(chunks[i] == 0){ ok = true; i++;}
		if(ok){
			counter++;
		}else{
			i++;
		}
	}

	if(chunks[n-2] != chunks[n-1]) counter--;

	return counter;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n; cin >> n;
	val.resize(n);
	g.resize(n, vector<int>());
	visited.resize(n); chunks.resize(n);
	for(int& x: val) cin >> x;

	for(int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cout << solve();
    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
