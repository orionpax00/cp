#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
 
  int n;cin>>n;
  int arr[n][3];
  for(int i =0; i < n ; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
 
  vector<vector<int>> dp(n, vector<int>(3,0));
  // dp.assign(0, vector<int>);

  dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][2];
  for(int i=1; i<n; i++){
    for(int j =0 ; j < 3 ; j++){
      for(int k = 0; k<3 ; k++){
        if(k != j)
          dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
      }
    }
  }
  cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
  return 0;
}