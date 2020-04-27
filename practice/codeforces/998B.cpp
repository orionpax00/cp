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
  int n,t,b, tprev ; cin >> n >> b;
  int even = 0;
  int odd = 0;
  vector<int> cost;
  bool isempty = true;
  for(int i = 0 ; i < n; i++){
    cin>>t;
    if(even == odd && even+odd != 0) {
      if(i+1 < n){cost.push_back(abs(tprev - t)); isempty = false;}
      even = 0; odd = 0;
    }
    if(t%2 == 0) even++;
    else odd++;
    tprev = t;
  }
  
  if(isempty) {cout<<0; return 0;};
  sort(cost.begin(), cost.end());

  // for(int x : cost)cout<<x <<" ";
  // cout<<"\n";
  int ans = 0;
  int sum = 0;
  for(int x : cost) {
    sum+=x;
    ans++;
    if(sum == b) {cout<<ans; return 0;}
    else if(sum > b) {
      cout<<ans-1; return 0 ;
    }
  };
  cout<<ans;

  return 0;
}