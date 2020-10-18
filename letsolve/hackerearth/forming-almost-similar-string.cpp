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
//void __print(graph::edge x) {cerr << "{" << x.from << "," << x.to << "," << x.cost <<"}";}

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


int Cst(int x,int y){
  if(y>=x) return min(x+25-y+1,y-x);
  else return min(x-y,25-x+y+1);
}

void solve(){
	string s1, s2;int k; cin >> s1 >> s2 >> k;
	string s = s1 + s2;
	sort(s.begin(), s.end());
	int n = s.length();
 	int ans = 0;
	for(int t = 0; t+ k < 26; t++){
		int i = 0; int j = t+k;
		int tans = 0;
		for(; i < n; i++){
			tans += max(0, min(Cst(s[i] - 'a', t),Cst(s[i] - 'a', j)) - k);
		}
		ans = min(ans, tans);
	}

	debug(s);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; 
	cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
