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
  // cin>>a[];
  for(int i = 0; i<n; i++){
    cin >> a[i];
  }
    for (int t = 0; t < (1 << n); t++) {
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) x += a[i];
      else x -= a[i];
    }
    if (x % 360 == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}