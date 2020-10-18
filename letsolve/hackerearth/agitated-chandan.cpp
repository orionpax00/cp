#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> visited;
vector<int> p;
vector<int> deg;

void init(int n){
	g.clear(); g.resize(n, vector<pair<int, int>>());
	dist.clear(); dist.resize(n);
	visited.clear(); visited.resize(n);
	p.clear(); p.resize(n);
	deg.clear(); deg.resize(n);
}


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


void dfs(pair<int, int> v){
	visited[v.first] = 1;
	debug(dist);
	dist[v.first] = max(dist[v.first] , dist[p[v.first]] + v.second);
	for(auto u : g[v.first]){
		if(!visited[u.first]){	
			p[u.first] = v.first; 
//			dist[u.first] = max(dist[u.first] , dist[v] + u.second);
			dfs(u);
		}
	}
}


void solve(){
	int n; cin >> n;
	init(n);
	for(int i =0; i < n - 1; i++){
		int a, b, c; cin >> a >> b >> c; --a; --b;
	 	g[a].push_back({b, c});	
	 	g[b].push_back({a, c});
		deg[a]++;
		deg[b]++;	
	}
	
	int ans = 0;

	for(int i = 0; i  < n; i++){
		dist.assign(n, 0);
		p.assign(n, -1);
		if(deg[i] == 1) 
			dfs({i, 0});
		ans = max(ans, *max_element(dist.begin(), dist.end()));
	}
	debug(g, dist, p);
	int cost = 0;
	if(ans > 100) cost = 100;
	if(ans > 1000) cost = 1000;
	if(ans > 10000) cost = 10000;
	cout << cost  << " " << ans << "\n";
		
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
