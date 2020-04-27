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
  int n ; cin>> n;
  // int arr[n]
  int ne=0;
  int zeros = 0;
  long long int sum = 0;
  for(int i = 0; i< n ; i++){
    int t ; cin >> t;
    if(t == 0) {
      sum++;
      zeros++;
    }
    else if(t <0){
      sum += -t - 1;
      ne++;

    }else if(t>0){
      sum += t-1;
    }
  }
  if(ne&1 && zeros == 0){
    sum += 2;
  }
  cout<<sum;

  return 0;
}