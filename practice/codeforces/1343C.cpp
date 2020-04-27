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
  int t ; 
  cin >> t;
  while(t--){
    int n; cin >> n ;
    long long int arr[n];
    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
    }
    pair<int, long long int> prevneg = {0,0};
    pair<int, long long int> prevpos = {0,0};
    for(int i = 0; i < n ; i++){
      if( arr[i] < 0) {
        long long int tmax = arr[i];
        int j = i+1;
        while(j<n && arr[j] * arr[j-1] > 0 ){
          tmax = max(tmax, arr[j]);
          j++;
        }
        i = j - 1;
        prevneg.second = prevpos.second + tmax;
        prevneg.first = prevpos.first + 1; 
      }else{
        long long int tmax = arr[i];
        int j = i+1;
        while(j<n && arr[j] * arr[j-1] > 0){
          tmax = max(tmax, arr[j]);
          j++;
        }
        i = j-1;
        prevpos.second = prevneg.second + tmax;
        prevpos.first = prevneg.first + 1; 
      }
    }

    long long int ans = {prevpos.first > prevneg.first ? prevpos.second : prevneg.second};

    cout<<ans<<"\n";
  }

  return 0;
}