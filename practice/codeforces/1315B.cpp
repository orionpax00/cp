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

  int t;
  cin>>t;
  while(t--){
    long long int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    map<char, long long int> prices={{'A',a},{'B', b}};
    const int n = s.length();
    vector<long long int> dp(n+1, 0);
    char pre = s[0];
    dp[1] = prices[s[0]];
    for(int i = 1; i<n; i++){
      if(s[i] == pre)
        dp[i+1] = dp[i];
      else{
        pre = s[i];
        dp[i+1] = dp[i] + prices[s[i]];
      }
    }
    long long int counter=0;
    for(int i = 0; i < n ; i++){
      counter++;
      if(dp[n-1]-dp[i] <= p && dp[i] != dp[i+1]) break;
    }
    cout<<counter << " \n";

  }

  

  return 0;
}

// bus tram p
// 3 2 8
// * A A B B B B A A B B *