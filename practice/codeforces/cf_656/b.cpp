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


template<typename T>
void lcs(vector< vector<int> >& dp, T& a, T& b){

  int n = dp.size() - 1;
  int m = dp[0].size() - 1;
  for(int i = 0; i <= n; i++) dp[i][0] = 0;
  for(int i = 0; i <= m; i++) dp[0][i] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1] &&  i != j) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  /* //memory optimized: will not work for lcs printing
    int n = a.size();
    int m = b.size();
    bool bi;
    for(int i = 0; i <= n; i++){
      bi = i & 1;
      for(int j = 0; j <= m; j++){
        if(i == 0 || j == 0) dp[bi][j] = 0;
        else if(a[i-1] == b[j-1]) dp[bi][j] = 1 + dp[1 - bi][j-1];
        else dp[bi][j] = max(dp[1 - bi][j], dp[bi][j-1]);
      }
    }
    return bi; // change return type to int; ans would be dp[bi][m]
  */
  
}



template<typename T>
vector<int> print_lcs(vector<vector<int>>& dp, T& a, T& b){
  vector<int> ans; // define typename char. int, double etc.
  int i = a.size();
  int j = b.size();

  while(j>0 && i>0){
    if (a[i-1] == b[j-1] && i != j){ 
      ans.push_back(a[i-1]);
      i--; j--; 
    }
    else if (dp[i-1][j] > dp[i][j-1]) i--; 
    else j--; 
  };

  reverse(ans.begin(), ans.end());
  return ans;
}

void solve(){
	int n; cin >> n;
	vector<int> v(2 * n); 
	for(int i = 0; i <2*n; i++) cin >> v[i];
	vector<vector<int>> dp(2*n+1, vector<int>(2*n+1));

	lcs(dp, v, v);

	debug(dp);

	vector<int> ans = print_lcs(dp, v, v);
	for(int x : ans) cout << x <<  " " ;
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
