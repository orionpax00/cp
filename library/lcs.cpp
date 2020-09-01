template<typename T>
void lcs(vector< vector<int> >& dp, T& a, T& b){

  int n = dp.size() - 1;
  int m = dp[0].size() - 1;
  for(int i = 0; i <= n; i++) dp[i][0] = 0;
  for(int i = 0; i <= m; i++) dp[0][i] = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
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
