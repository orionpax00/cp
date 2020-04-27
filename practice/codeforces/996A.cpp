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
  int n ; cin >> n;
  int arr[5] = {100,20,10,5,1};
  int counter = 0;
  for(int x : arr){
    while(true){
      if(n-x >= 0){
        counter++;
        n -= x;
      }else{
        break;
      }
    }
  }
  cout<<counter;
  return 0;
}