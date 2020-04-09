//	Minimum Range Queries Sparse Table Method
//	Sparse-Table DataStructure
#include <bits/stdc++.h>

using namespace std;

// time complexity is O(Nlog(N))
vector<vector<int>> sparseTable(vector<int> vec){
  
  int MAXN = vec.size();
  int K = log(vec.size()) + 1;
  vector<vector<int>> st(MAXN+1, vector<int>(K+1));

  // st[i][j] = ans_for_range(i,i+2^j-1) // ans is like min, max, sum etc

  for(int i=0; i<MAXN; i++){
    st[i][0] = vec[i]; // j = 0
  }
  // j --> {0, K}
  for(int j=1; j<=K; j++){
    for(int i = 0; i + (1 << i) <= MAXN; i++){
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  return st;
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
  int MAXN = n;
  int K = log(n) + 1;

  int log[MAXN+1];
  log[1] = 0;
  for (int i = 2; i <= MAXN; i++)
      log[i] = log[i/2] + 1; // not even calculating log
  vector<vector<int>> st = sparseTable(input);
  int t;cin>>t;
  while(t--){
    int L, R; cin>>L>>R;

    int j = log[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    cout<<minimum<<"\n";
  }

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