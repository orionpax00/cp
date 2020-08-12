---
title: "topics"
author: Durgesh

html:
  offline: false

export_on_save:
  html: true

print_background: true
---


## Topics 

* Prefix Product and Suffix Product
* Prefix Sum and Suffix Sum
* Reducing Space complexity of Dynamic Programming solution.
* Amortization 

### Answer sum queries 
Given an array A=[a1, a2, a3, ..., an] for Q = [{l1,r1}, {l3,r2}, {l3, r3}, ...]

* Prefix array
* sparse table
* sqrt decomposition
* segment tree

#### Prefix Array

```cpp
class prefixArray {
    vector<int> v;

    public:
    prefixArray(const vector<int> &vi) {
        int n = vi.size();
        v.resize(n+1);
        v[0] = 0;
        for(int i = 0 ; i < n ; i++) v[i + 1] = v[i] + vi[i];
    }

    int query(pair<int, int> p){
        return v[p.second] - v[p.first - 1]; // query has 1 based indexing
    }
};
```


#### Sparse Table

```cpp
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
```