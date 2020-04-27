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
  int n, v;
  cin >> n >> v;
  int ans = {v < n-1 ? v : n-1};
  n -= 1;
  int tv = v;
  for(int i = 2 ; i <= n ; i++){
    tv--;
    if(tv <= n-i) {
      ans += i;
      tv++;
    }
  }
  cout<<ans;
  return 0;
}