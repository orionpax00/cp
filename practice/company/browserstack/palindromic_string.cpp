#include <bits/stdc++.h>

using namespace std;

int palSt(string& str){
  int l=0,r=str.length()-1;
  while(r>l){
    if(tolower(str[l] != tolower(str[r]))) return 0 ;
    else {l++;r--;}
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  getline(cin,str);
  cout<<palSt(str);

  return 0;
}
