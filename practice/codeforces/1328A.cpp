#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin>>t;
  while(t--){
    int a, b;cin>>a>>b;
    int ans = b*(a+b-1)/b - a%b - a + 1;
    if(a%b == 0) cout<<0<<"\n";
    else cout<<ans<<"\n";
  }
  
  return 0;
}
