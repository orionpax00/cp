template<typename T>
vector<vector<T>> sparseTable(vector<T> vec){
  
  int MAXN = vec.size();
  int K = log(vec.size()) + 1;
  vector<vector<T>> st(MAXN+1, vector<T>(K+1));

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