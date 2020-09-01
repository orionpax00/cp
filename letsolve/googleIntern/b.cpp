#include <bits/stdc++.h>
#define int long long

using namespace std;



template<typename A>
string tostring(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail >
void debug_out(Head H, Tail... T) {
	cerr << " " << tostring(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

bool lcs(vector<int>& a, vector<int>& b, vector< vector<int> >& dp){

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
 	 	return bi;

}


int solve(int N, int M, vector<int> A, vector<int> B){
	vector< vector<int> > dp(2, vector<int> (M+1));
	bool bi = lcs(A, B, dp);
	
	for(auto x : dp) debug(x);

	return N - dp[bi][M];
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto& x: a) cin >> x;
	for(auto& x: b) cin >> x;
	cout << solve(n, m , a, b);

    

  return 0;
}
