#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n, d; 
  cin >> n >> d ;
  string s;
  cin >> s;
  vector<int> dp(n+1,INT_MAX-5);
  dp[0] = 0;
  for(int i = 0 ; i < n ; i++){
    if(s[i] == '1'){
      for(int j = i-1 ; j >= i-d ; j-- ){
        if(j>=0 && s[j] == '1') dp[i] = min(dp[i], dp[j] + 1);
      }
    }
  }

  int ans = {dp[n-1] != INT_MAX-5 ? dp[n-1] : -1};
  cout<<ans;
  return 0;
}