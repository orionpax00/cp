template<typename T>
vector<...> print_lcs(vector<vector<int>>& dp, T a, T b){
  vector<...> ans; // define typename char. int, double etc.
  int i = dp.size();
  int j = dp[0].size();

  while(j>0 && i>0){
    if (a[i-1] == b[j-1]){ 
      ans.push_back(a[i-1]);
      i--; j--; 
    }
    else if (dp[i-1][j] > dp[i][j-1]) i--; 
    else j--; 
  };

  reverse(ans.begin(), ans.end());
  return ans;
}