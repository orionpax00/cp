#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  string a, b;
  cin>>a>>b;
  int n = a.length();
  int m = b.length();

  int dp[n+1][m+1];

  for(int i = 0; i <= n; i++){
    dp[i][0] = 0;
  }

  for(int i = 0; i <= m; i++){
    dp[0][i] = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  // cout<<dp[n][m]<<"\n";

  // for(int i = 0; i <= n; i++){
  //   for(int j = 0; j <= m; j++){
  //     cout<<dp[i][j]<<" ";
  //   }cout<<"\n";
  // }

  string ans="";
  int i = n;
  int j = m;

  while(j>0 && i>0){
    if (a[i-1] == b[j-1]){ 
      ans += a[i-1];
      i--; j--; 
    }
    else if (dp[i-1][j] > dp[i][j-1]) i--; 
    else j--; 
  };

  reverse(ans.begin(), ans.end());
  cout<<ans;

  return 0;
}