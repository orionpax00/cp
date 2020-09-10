#include <bits/stdc++.h>
//#define int long long

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
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
int n;
vector<int> depth;
vector<int> p;

void dfs(int v){
	depth[v] = 0;
	debug(v, p, depth);

	for(int u : g[v]){
		if(depth[u] == -1){
			depth[u] = 1 + depth[v];
			p[u] = v;
			dfs(u);
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int m; cin >> n >> m;
	g.resize(n, vector<int>());
	depth.resize(n); depth.assign(n, -1);
	p.resize(n); p.assign(n, -1); 

	for(int i = 0; i < m; i++){
		int f, t; cin >> f >> t; --f; --t;
		g[f].push_back(t);
		g[t].push_back(f);
	}


	for(int i = 0; i < n; i++){
		if(depth[i] == -1){
			dfs(i);
		}
	}

 	int max_ = INT_MIN, counter = 0, child;
	for(int i = 0; i < n; i++){
		counter = 0;
		for(int pv = i; pv != -1; pv = p[pv]){
			counter++;
		}
		if(counter > max_){
			max_ = counter; child = i;
		}
	}
	
	cout << max_ << "\n";
	
	for(int pv = child; pv != -1; pv = p[pv]){
		cout << pv + 1 << " ";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
