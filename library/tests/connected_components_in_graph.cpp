//Connected components in the graph
// dfs graphs 
#include <bits/stdc++.h>

using namespace std;

vector<int> processed;
vector<bool> isvisited;
vector< vector<int>> g;

void dfsiterative(int x){
  stack<int> s;
  s.push(x);
  
  while(!s.empty()){
    int u = s.top();
    s.pop();
    processed.push_back(u);
    isvisited[u] = true;
    for(auto i: g[u]){
      if(!isvisited[i]){
        s.push(i);
        isvisited[i] = true;
      }
    }
  }
};


void dfs(int x){
  isvisited[x] = true;
  processed.push_back(x);
  for(int i = 0 ; i < g[x].size(); i++){
    if(!isvisited[g[x][i]]){
      dfs(g[x][i]);
    }
  }
};

int findConnectedComponents() {
  int ans = 0;
  for(int i = 0 ; i < g.size() ; i++){
    if(!isvisited[i]){
      ans++;
      processed.clear();
      dfs(i);
      for(int i : processed){
        cout<<i<<" ";
      }cout<<"\n";
    }
  }
  cout<<"\nTotal Number of components\n";
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int N = 4;
  g.resize(N, vector<int>());
  g[0] = {1,2};
  g[1] = {3};
  g[2] = {1};
  g[3] = {1};

  isvisited.resize(N,false);

  int ans = findConnectedComponents();
  cout<<ans;
  
  return 0;
}