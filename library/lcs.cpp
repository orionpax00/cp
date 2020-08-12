void lcs(vector< vector<int> >& dp){

  int n = dp.size();
  int m = dp[0].size();
  for(int i = 0; i <= n; i++) dp[i][0] = 0;
  for(int i = 0; i <= m; i++) dp[0][i] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
}