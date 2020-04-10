#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n,k;cin>>n>>k;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  int dp[n];
  int INF = 1e9 + 5;
  memset(dp, INF, sizeof(int)*n);
  dp[0] = 0;
  for(int i=0; i<n; i++){
    for(int j=1; j<=k;j++){
      if(i+j<n)
        dp[i+j] = min(dp[i+j], dp[i] + abs(arr[i+j]-arr[i]));
    }
  }
  cout<<dp[n-1];
  return 0;
}
