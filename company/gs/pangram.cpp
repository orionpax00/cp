#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s = "abcdefghijklmnopqrstuvwxyz";
  string s2 = "im durgesh";
  int index=26;
  vector<bool> found(27,false);
  for(int i=0; i<s.length();++i){
    if(s[i] >= 'A' && s[i] <= 'Z') index = s[i] - 'A';
    else if(s[i] >= 'a' && s[i] <= 'z') index = s[i] - 'a';
    found[index] = true;
  }
  
  bool ispangram=false;
  for(int i=0; i<=25;i++){
    if(!found[i]) {cout<<"no"; ispangram=true;break;}
  }
  if(!ispangram) cout<<"yes";

  return 0;
}