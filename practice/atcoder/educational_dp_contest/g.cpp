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
  int n, m;
  cin>>n>>m;
  vector<vector<int>> g(n+1, vector<int>());  
  g[0] = {0};

  for(int i =0 ; i<m; i++){
    int t,t2; cin>>t>>t2;
    g[t].push_back(t2);
  }

  int ans= INT_MIN;
  vector<int> visited(n,0);

  for(int z = 1 ; z<n;z++){
  int tempans  = 1;
    if(!visited[z]) {
      stack<int> s;
      s.push(z);
      visited[z] = 1;
      while(!s.empty()){
        int x = s.top();
        s.pop();
        for(int i : g[x]){
          if(!visited[i]) {visited[i] = 1; s.push(i); tempans++;};
        }
      }
    }
    ans = max(ans, tempans);
  }  

  cout<<ans;

  return 0;
}