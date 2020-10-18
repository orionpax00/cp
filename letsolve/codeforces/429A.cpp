#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



vector<vector<int>> g;
vector<int> visited;
vector<int> parity;
vector<int> goal;
vector<int> ans;

void dfs(int u, int d, int e, int o){
	visited[u] = 1;
	int val = parity[u];
	if(e&&d%2 == 0)
		val = (val^1);
	if(o&&d%2 == 1)
		val = (val^1);

	if(val != goal[u]){
		if((d&1)) o ^= 1;
		else e ^= 1;
		ans.push_back(u);
	}

	for(int v : g[u])
		if(!visited[v]) dfs(v, d+1, e, o);
	
}


void solve(){
	int n; cin >> n;
	g.resize(n, vector<int>());
	visited.resize(n); parity.resize(n); goal.resize(n);

	for(int i = 0; i < n - 1; i++){
		int a, b; cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	for(int& x : parity) cin >> x;
	for(int& x : goal) cin >> x;

	debug(g);
	debug(parity, goal);
	
	dfs(0, 0, 0, 0);
	debug(parity);
	debug(ans, ans.size());
	cout << ans.size() << "\n";
	for(int i : ans) cout << i+1 << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
