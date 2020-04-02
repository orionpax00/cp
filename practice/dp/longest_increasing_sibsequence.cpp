/*
  longest increasing subsequence means every upcoming element is larger the privous one elements
  6 2 5 1 7 4 8 3
  ans 2 5 7 8


  solution
  calculate length of longest increasing sub sequence that end s at the given index of the array
  for example is the previous array
  1 1 2 1 3 2 4 2
*/

// this solution has time complexity of O(n^2) and space complexity of O(n)
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);


  int t;cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int& x:arr) cin>>x;

    int leng[n];
    for(int i=0; i<n;i++){
      leng[i] = 1;
      for(int j = 0; j<i; j++){
        if(arr[j] < arr[i]) leng[i] = max(leng[i], leng[j]+1);
      }
    }
    int max_ = INT_MIN;
    for(int x : leng) if(max_ <x) max_ =x;
    cout<<max_<<"\n";
  }
}