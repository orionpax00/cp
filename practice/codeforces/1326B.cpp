#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin>>t;
  int cumm=0;
  while(t--){
    int x;cin>>x;
    cout<<cumm+x<<" ";
    cumm = max(cumm, cumm+x);
  }

  return 0;
}