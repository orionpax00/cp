#include <bits/stdc++.h>
//#define int long long

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


bool isinter(string a, string b, string c){
	int n = a.length(), m = b.length(), p = c.length();

	if(p != n + m) return false;
	if(p == 0) return true;
	
	vector< vector<int> > dp(n + 1, vector<int>(m + 1));	
	dp[0][0] = 1;	
	for(int i = 1; i <= n; i++)
		if(c[i - 1] == a[i - 1]) dp[i][0] = dp[i - 1][0];
	for(int i = 1; i <=m; i++)
		if(c[i - 1] == b[i - 1]) dp[0][i] = dp[0][i-1];
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			if(c[i+j - 1] == a[i - 1] && c[i+j - 1] == b[j -1])	dp[i][j] = dp[i - 1][j] || dp[i][j-1];
			else{ 
				if(c[i+j - 1] == a[i-1]) dp[i][j] = dp[i-1][j];
				else if(c[i+j - 1] == b[j - 1]) dp[i][j] = dp[i][j-1];
				else continue;
			}
		}
	}

	for(int i = 0 ; i <= n ; i++) debug(dp[i]);

	int ans = 0;
	vector<int> t(m+1);
	for(int i = 0 ; i <=m; i++) t[i] = dp[0][i];
	for(int i = 1; i <= n; i++){
		debug(t);
		for(int j = 0; j <= m; j++){
			if(!dp[i][j]) ans = 0;
			else{
				ans = ans + t[j];
			}
			t[j] = ans;
		}
		ans=0;
	}
	debug(t);
	cout << t[m] << "\n";
	return dp[n][m] == 1;
 
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string a = "aabcc", b = "dbbca", c = "aadbbcbcac";
	cout << isinter(a, b, c);	
    

  return 0;
}
