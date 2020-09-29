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



vector<vector<int>> ans;
vector<int> ss;
vector<int> v;
int N;


void solve(int idx){
	
	ans.push_back(ss);

	for(int i = idx; i < N; i++){	
		ss.push_back(v[i]);
		solve(i + 1);
		ss.pop_back();
	}
	return;
};
void solvedp(){
	for(int i = 0; i < (1 << N); i++){
		vector<int> vt;
		for(int j = 0; j < N; j++){
			if((i & (1 << j)) != 0) vt.push_back(v[j]);
		}
		ans.push_back(vt);
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N; v.resize(N); for(int& x: v) cin >> x;
//	solve(0);
	solvedp();
 	debug(ans);   


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
