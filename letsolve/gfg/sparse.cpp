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


void solve(){
	int	m, n, n_; cin >> n >> m >> n_;
	vector<vector<int>> a(m, vector<int>(n, -1));

	for(int i = 0; i < n_; i++){
		int ar, b, c; cin >> ar >> b >> c;
	 	a[ar][b] = c;
	}
	
	m--; n--;

	for(int i = 0 ; i <= m; i++){
		for(auto x : a[i]) cerr << x << " ";
		cerr <<"\n";
	}
	
	int i, si, sj; 
	cin >> si >> sj;
    stack<int> stk; int t1 = si; int t2 = sj;
  
    while (t1 < m && t2 < n){ 
        for (i = si; i < t1 + 1; ++i) 
			if(a[i][sj] != -1)
				cout << a[i][sj] << " ";  
        t1++; si++;
  
        for (i = sj + 1; i < t2 + 1; ++i) 
			if(a[si - 1][i] != -1)
				cout <<  a[si - 1][i] <<  " ";
        t2++; sj++;
  
        //for(i = si - 1; i >= 
    } 

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
