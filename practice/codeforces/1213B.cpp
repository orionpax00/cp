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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0 ; i< n ; i++){
      cin>>arr[i];
    }
    int ans=0;
    int m = arr[n-1];
    for(int i = n-1 ; i>=0; i--){
      if(arr[i] > m) ans++;
      m = min(m, arr[i]);
    }
    cout<<ans<<"\n";

  }
  return 0;
}