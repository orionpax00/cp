#include <bits/stdc++.h>

using namespace std;
vector<string> chToStr(vector<string> v);

vector<string> chToStr(vector<string> v){
  vector<string> 
  for(int i=0;i<v.size();++i){
    int start =0;
    string t= "";
    for(int j=1;j<v[i].length();j++){
      if(v[i][j] == '.'){
        while(--2){
          t+=v[i][j-1];
        }
      }else if(v[i][j] == '+'){
        while(--2){
          t+=v[i][j-1];
        }
      }
      else if(v[i][j] == '*'){
        while(--5){
          t+=v[i][j-1];
        }
      }
    }
  }
  return v;
}

void solution(string s, vector<string> v){
  vector<string> V = chToStr(v);
  for(auto x: V) cout<<x<<"\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str="aaaaaannndnnnnnnfffhfhhgjjjwkkkllclc";
  vector<string> V={"a.","n+","a*","an.","a.d."};
  solution(str, V);
  return 0;
}