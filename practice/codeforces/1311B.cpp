// dfs sorting	
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  
  int t;cin>>t;
  while(t--){
    int n , m;cin>>n>>m;
    int arr1[n];int arr2[n];
    memset(arr2, 0, n*sizeof(int));
    for(int i=0; i<n;i++){
      cin>>arr1[i];
    }
    for(int i=0; i<m;i++){
      int x; cin>>x;
      arr2[x -1] =1;
    }
    while(true){
      bool isswaped = false;
      for(int i =0;i<n-1; i++){
        if(arr2[i] && arr1[i] > arr1[i+1]){
          swap(arr1[i], arr1[i+1]);
          isswaped=true;
        }
      }
      if(!isswaped) break;
    }

    if(is_sorted(arr1, arr1+n)) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}

// 2 1 4 3
// 1 3