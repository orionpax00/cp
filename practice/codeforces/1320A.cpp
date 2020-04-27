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

  int n;
  cin >> n;
  int arr[n];
  for(int  i = 0 ; i < n ; i++){
    cin>>arr[i];
  }

  // vector<int> dp(n,0);
  map<long long int, long long int> ans;
  for(int i = 0 ; i< n ; i++){
      ans[arr[i] - n - i] += arr[i];
  }

  // int ans = 0;
  long long int tmax = INT_MIN;

  for(auto x : ans){
    tmax = max(tmax, x.second);
  }
  cout<<tmax;

  return 0;
}