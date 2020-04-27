#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #endif
  int n ; cin >> n ;
  int arr[n];
  int ans = INT_MIN;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < n ; i++){
    int j = i;
    while(j+1<n && arr[j+1] <= 2*arr[j]){
      j++;
    }
    ans = max(ans, j-i+1);
    i = j;
  }
  cout<<ans;
  return 0;
}