//	Best tiem to buy or sale stocks
//	DP
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n; cin>>n;
  int input[n];
  for(int i =0; i<n;i++){
    cin>>input[i];
  }
  // buyer will have two states with stock or without stock

  // int best_without_stock=0, best_with_stock=INT_MIN;

  // for(int x: input){
  //   best_without_stock = max(best_without_stock, best_with_stock+x); 
  //   best_with_stock = max(best_with_stock, best_without_stock-x);
  // }

  // cout<<best_without_stock;

  // using Dynamic programming same solution as above
  // dp[i][0] --> best_without_stock
  // dp[i][1] --> best_with_stock

  int dp[n][2];
  dp[0][0] = 0;
  dp[0][1] = INT_MIN;

  for(int i=1; i<n; i++){
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + input[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - input[i]);
  }
  cout<<dp[n-1][0];

  return 0;
}

