#include <bits/stdc++.h>
//#define int long long

using namespace std;


vector<vector<int>> g;

vector<vector<int>> visited;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	g.resize(n, vector<int>(m));
	visited.resize(n, vector<int>(m));

	
	pair<int, int> c;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int t; cin >> t;	
			if(t == 9) {c.first = i, c.second = j; g[i][j] = 1}
			else g[i][j] = t;
		}
	}

	vector<vector<int>> dp(n+1, vector<int>(m+1));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
