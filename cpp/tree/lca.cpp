#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t={{1,2},{4,5},{},{},{6,7},{},{}};

int LCA(int curr, int a, int b){
  if(t[curr].size()==0) return -1;
  if(curr == a || curr == b) return curr;

  int l = LCA(t[curr][0],a,b); 
  int r = LCA(t[curr][1],a,b);

  if(l != -1 && r != -1) return curr;
  if(l == -1) return r;
  else return l;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<LCA(0,3,4);
  return 0;
}