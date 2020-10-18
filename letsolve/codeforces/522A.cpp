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

map<string, vector<string>> g;
int max_height = 1;
void dfs(string s, int level){
	max_height = max(max_height, level);
	for(auto x : g[s]){
		dfs(x, level+1);
	}
}

void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string t, r, f; cin >> t >> r >> f;
		transform(t.begin(), t.end(), t.begin(), ::tolower); 
    transform(f.begin(), f.end(), f.begin(), ::tolower); 
		g[f].push_back(t);
	}

	for(auto x : g){
		dfs(x.first, 1);
	}
	for(auto x : g){
		cerr << x.first << " : ";
		for(auto y : x.second)
			cerr << y << " ";
		cerr << "\n";
	}

	cout << max_height;
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
