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
  string s; cin>>s;
  int n = s.length();
  char tobeput[3] = {'a','b','c'};
  int k = 0;
  if(s.length() == 2){
    s[1] = tobeput[0];
    while(s[1] == s[0]){
      s[1] = tobeput[k+1]; k++;
    }
  }
  for(int i = 1; i< n-1; i++){
    k = 0;
    if(s[i-1] == s[i]){
      s[i] = tobeput[0];
      while(s[i+1] == s[i] || s[i-1] == s[i]){
        s[i] = tobeput[k+1]; k++;
      }
    }
  }
  
  k = 0;
  if(s[n-2] == s[n-1]){
    s[n-1] = tobeput[0];
    while(s[n-1] == s[n-2]){
      s[n-1] = tobeput[k+1]; k++;
    }
  }
  cout<<s;
  return 0;
}