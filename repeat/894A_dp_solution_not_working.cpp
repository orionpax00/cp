#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  string a,b;
  cin>>a;
  b = "QAQ";
  int n = a.length();
  int m = b.length();

  int dp[n+1][m+1];

  for(int i = 0; i <= n; i++){
    dp[i][0] = 1;
  }

  for(int i = 0; i <= m; i++){
    dp[0][i] = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  cout<<dp[n][m];
  
  return 0;
}

//LCS 