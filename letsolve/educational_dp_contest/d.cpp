#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, w;cin >> n >> w;
  int arr[n+1][2];
  arr[0][0] = 0;
  arr[0][1] = 0;

  for(int i =0 ; i< n ; i++){
    cin>>arr[i+1][0] >> arr[i+1][1]; 
  }
  vector<vector<long long>> dp(n+1, vector<long long>(w+1,0));

  for(int i=1; i<n+1;i++){
    for(int j=1;j<w+1; j++){
      if(j-arr[i][0]>=0){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i][0]] + arr[i][1]);
      }
      else
        dp[i][j] = dp[i-1][j]; 
    }
  }
  cout<<dp[n][w];
  return 0;
}

