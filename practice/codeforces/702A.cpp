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
  int fans = 0;
  int ans = 0;
  int prev = INT_MIN;
  for(int i = 0 ; i < n ; i++){
    int t; cin >> t; 
    if(t > prev){
      prev = t;
      fans = max(fans, ++ans);
    }else{
      ans = 1;
      prev = t;
    }
  }

  cout<<fans;


  return 0;
}