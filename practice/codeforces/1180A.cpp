#include <bits/stdc++.h>

using namespace std;

long long int ans(int n){
  if(n == 1) return 1;
  return ans(n-1) + (n-2)*4 + 4;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n ; cin >> n ;
  cout<<ans(n);
  return 0;
}