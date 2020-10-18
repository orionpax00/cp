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
vector<int> in_deg;
vector<int> order;
vector<int> out_deg;
vector<double> prob;


void dfs(int v){
	visited[v] = 1;
	for(int u : g[v]){
//		if(!visited[u]){
			prob[u] += prob[v]/out_deg[v];
			dfs(u);
	//	} 
	}
	order.push_back(v);
}


void solve(){
	int n, m, r; cin >> n >> m >> r;
	g.resize(n, vector<int>());
	visited.resize(n);
	in_deg.resize(n); out_deg.resize(n); prob.resize(n); prob.assign(n , 0.0);
	prob[r - 1] = 1;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		in_deg[b]++;
		out_deg[a]++;
	}
	dfs(--r);
	double mx = -1.0;
	vector<int> ans;
	for(int x : order){
		if(out_deg[x] == 0)
			mx= max(mx, prob[x]);
	}
	
	//debug(prob);
	for(int x :order){
		if(out_deg[x] == 0 && prob[x] == mx)
			ans.push_back(x);
	}
	for(int x : ans) cout << x << " ";
	debug(ans);
	return;	
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
