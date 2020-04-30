#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n ; cin >> n;
  vector<ll> v(n);
  vector<ll> upref(n+1,0);
  upref[0] = 0;
  for(int i = 0; i < n ; i++){
    ll t; cin>>t;
    v[i] = t;
    upref[i+1] = upref[i]+t;
  }

  sort(v.begin() , v.end());
  vector<ll> opref(n+1,0);
  opref[0] = 0;
  for(int i = 0 ; i < n ; i++) opref[i+1] = opref[i] + v[i];

  int m; cin>>m;
  while(m--){
    int l , r , type; cin >> type >> l >> r;
    if(type == 1){
      cout<<upref[r] - upref[l-1]<<"\n";
    }else{
      cout<<opref[r] - opref[l-1]<<"\n";
    }
  }

  return 0;
}