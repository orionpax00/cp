#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;string s;cin>>t>>s;
  if(t%2 != 0) {cout<<"No";return 0;}
  else{
      if(t>2){
        int i=0;
        int j = s.length()/2 - 2;
        for(i; i<j; i++) {
          if(s[i] != '('){cout<<"No"; return 0;}
        }
        for(i=j+3; i<s.length(); i++) {
          if(s[i] != ')'){cout<<"No"; return 0;}
        }
      }
  }
  if(s[t/2-1] != s[t/2]) cout<<"Yes";
  else cout<<"No";
  
  return 0;
}
