#include <bits/stdc++.h>

using namespace std;

string bPalin(string& str){
  int n = str.length();
  if(n == 1) return "";
  for(int i=0; i<n/2; ++i){
    if(str[i] != 'a') {str[i] = 'a'; return str;};
  };
  str[n-1] = 'b';
  return str;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  getline(cin,str);
  cout<<bPalin(str);
  return 0;
}