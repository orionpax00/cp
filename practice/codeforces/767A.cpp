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
  set<int> arr;
  int j = 0;
  for(int i =0 ; i< n ; i++){
    int t;
    cin>>t;
    arr.insert(t);
    while(arr.count(n-j) == 1){
      cout<<n-j<<" "; j++;
    }
    cout<<"\n";
  }

  return 0;
}