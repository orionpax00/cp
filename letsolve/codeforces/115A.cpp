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

int t = 1;
int h = 0;

void dfs(int u, int t){
	h = max(h, t);
	visited[u] = 1;
	for(int x : g[u]){
//		if(!visited[x]){
			dfs(x, t+1);
	//	}
	}
}


void solve(){
	int n; cin >> n;
	visited.resize(n);
	g.resize(n, vector<int>());

	for(int i = 0; i < n; i++){
		int t; cin >> t;
		if(t == -1) continue;
		else{
			g[t - 1].push_back(i);
//			g[i].push_back(t-1);
		}
	}

	debug(g);
	for(int i = 0; i < n; i++){
		//if(!visited[i])
			dfs(i, 1);
	}
	debug(h, t);

	cout << h;

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
