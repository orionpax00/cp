#include<bits/stdc++.h>
using namespace std;

bool bogosort(vector<int> v){
  int n= v.size();
  for(int i=0; i<n-1;i++){
    for(int j=i+1; j<n; j++){
      if(j - v[j] == i - v[i]) return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int n;
  cin>>n;
  vector<int> per(n);
  for (int i=0; i<n; i++){
    cin>>per[i];
  }
  do{
    if(bogosort(per)){
      
    }
  }while(next_permutation(per.begin(), per.end()));
  
  return 0;
}