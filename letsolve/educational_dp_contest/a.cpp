#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  const int INF = 1e9 + 5;
  
  int n;
  cin>>n;
  int arr[n];
  for(int& x: arr){
    cin>>x;
  };
  vector<int> dp(n,INF);
  dp[0] = 0;
  for(int i=0;i<n;i++){
    for(int j :{i+1, i+2}){
      if(j<n){
        dp[j] = min(dp[j], dp[i]+abs(arr[i] -  arr[j]));
      }
    }
  }
  cout<<dp[n-1];
  return 0;
}
