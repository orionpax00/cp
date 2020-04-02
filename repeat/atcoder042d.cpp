#include <bits/stdc++.h>

using namespace std;

#define m 1e9+7

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int h,w,a,b;
  cin>>h>>w>>a>>b;  

  vector<vector<int>> dp(h, vector<int>(w));
  for(int i = 0; i<h-a;i++) dp[i][0] = 1;
  for(int i = 0; i<w;i++) dp[0][i] = 1;
  
  for(int k = 1 ; k < h; k++){
    for(int j = 1 ; j<w; j++ ){
      if(k >= h-a && j < b) continue;
      dp[k][j] = dp[k-1][j] + dp[k][j-1];
    }
  }
  int ans = dp[h-1][w-1] % 1000000007;
  cout<<ans<<"\n";
  // for(int k = 0 ; k < h; k++){
  //   for(int j = 0 ; j<w; j++ ){
  //     cout<<dp[k][j]<<" ";
  //   }cout<<"\n";
  // }


  return 0;
}