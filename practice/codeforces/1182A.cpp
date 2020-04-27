#include <bits/stdc++.h>

using namespace std;
int pow_(int n , int k){
  int ans=1;
  while(k--){
    ans *= n;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n ;
  cin >> n ;
  if(n&1 == 1){
    cout<<0;
    return 0;
  }else{
    cout<<pow_(2, n/2);
    return 0;
  }
  return 0;
}