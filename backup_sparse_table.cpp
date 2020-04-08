//	Minimum Range Queries Sparse Table Method
//	Sparse-Table DataStructure
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sparseTable(vector<int> vec){
  vector<vector<int>> ans;

  int n = vec.size();
  while(n>0){
    vec
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
  vector<int> input(n);
  for(int i=0; i<n;i++){
    cin>>input[i];
  }

  //Precomputation


  return 0;
}

// Notes:
// * Best to compute maximum or minimum range queries
//   ## Intution 
//   * Any non negative number can be represented as a 
//     decreasing power of 2.
//   * 13 --> 1101 --> 8 + 4 + 0x2 + 1
//   * any range query interval can also be written as union of these
//     smaller interval of range power of 2
//   * The idea is to precompute all range queries of range power of 2
//     and than for actual range query split it into union sets of 2

// Note: where arr[i][j] will store the answer for [i,i+2j−1] of length 2j