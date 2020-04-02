#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; string st;
  cin>>t>>st;

  char s[t];
  strcpy(s, st.c_str());

  bool run_ = true;
  int sum=0;
  while(run_){
    
    char ml = 'a';
    int pos=0;
    for(int i =0; i<t; i++){
      if((char) s[i] > ml) {
        ml = (char) s[i];
        pos = i;
      }
    }
    if(pos>=1 && pos <t-1){
      if((s[pos-1] - s[pos] == -1) || (s[pos+1] - s[pos] == 1)){
        for(int i=pos; i<t-1; i++){
          s[i] = s[i+1];
        }
        sum++;t--;
      }
    }else{
      run_ = false;
    }
  }
  cout<<sum;
  return 0;
}

