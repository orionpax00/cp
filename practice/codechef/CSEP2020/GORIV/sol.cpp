#include <bits/stdc++.h>
//#define int long long

using namespace std;

map< string, vector<string> > g;
map<string, int> visited;
int count_ = 0;


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


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int tt; cin >> tt;
	while(tt--){
		count_ = 0;
		int n; cin >> n;
		string st; cin >> st;
		vector<string> v;
	 	map<string, int> m; 	
		for(int i = 0; i < n; i++){
			string a, b; cin >> a >> b;
			g[a].push_back(b);
			v.push_back(a);
			m[a] = 0;
		}
		debug(m, v);
		for(auto x : g){
			debug(x.first, x.second);
			int tempc = 0; m[x.first]++;
			for(string xx: x.second){
				if(m.count(xx)) tempc++;
			}

			count_ += x.second.size() -  tempc;
		}

		cout << count_ << "\n";

	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
