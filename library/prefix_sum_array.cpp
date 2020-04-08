//	Prefix Sum Arrray
//	Array range_queries
#include <bits/stdc++.h>

using namespace std;

vector<int> prefixSumArray(vector<int> vec){
  int n = vec.size();
  vector<int> ans(n);
  ans[0] = vec[0];
  for(int i=1; i<n;i++){
    ans[i] = ans[i-1]+vec[i];
  }
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n; cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n;i++){
    cin>>arr[i];
  }

  //preprocess seperately
  arr = prefixSumArray(arr);
  
  // range sum queries
  int t;cin>>t;
  while(t--){
    int a, b;cin>>a>>b;
    cout<<arr[b] - arr[a]<<"\n"; //(a, b]
  }

  return 0;
}