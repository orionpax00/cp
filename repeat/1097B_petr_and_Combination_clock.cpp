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
  int a[n];
  cin>>a[0];
  for(int i = 1; i<n; i++){
    int t ; cin >> t;
    if(a[i-1]%360 == 0)
      a[i] = t;
    else
      a[i] = a[i-1] + t;
  }
  if(a[n-1]%360 == 0){
    cout<<"YES";return 0;
  }else{
    for(int x: a){
      if(a[n-1] - x == x){
        cout<<"YES"; return 0;
      }
    }
  }
  cout<<"NO";
  #ifdef LOCAL
    for(int x: a) cout<<x<<" "<<a[n-1]-x<<"\n";
  #endif

  return 0;
}