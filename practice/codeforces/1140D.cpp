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
  int n;cin>>n;
  long long int ans=0;
  for(int i = 2; i<n; i++){
    ans += i*(i+1);
  }
  cout << ans;
  return 0;
}