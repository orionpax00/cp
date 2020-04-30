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
  int n, k;  cin >> n >> k;
  vector<int> pref(n+1);
  for(int i = 0 ; i < n ; i++){
    int t; cin >> t ;
    pref[i+1] = pref[i] + t ;
  }
  int j = k;
  int i = 0;
  int min_ = INT_MAX;
  int ans = 0;
  while(j <= n){
    if(pref[j] - pref[i] < min_){
      min_ = pref[j] - pref[i];
      ans = i;
    }
    j++;
    i++;
  }
  cout<<ans+1;
  return 0;
}