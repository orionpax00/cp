#include <bits/stdc++.h>

/*
  Hi I'm Durgesh
*/


using namespace std;

string lcp(vector<string> vStr){
  
  int end = 0;

  for(int i=0;i<vStr[0].length(); ++i){
    for(int j = 1; j<vStr.size(); ++j){
      try{
        if(vStr[0][i] != vStr[j][i]) {end = i; break;}
        else continue;
      }catch(int i){
        end = i-1; break;
      }
    }
    if(end>0){
      break;
    }
  }
  return vStr[0].substr(0,end);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<string> str={"abab", "ab", "abcd"};

  cout<<lcp(str);

  return 0;
}

