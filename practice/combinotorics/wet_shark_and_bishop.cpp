#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  int m = n;
  vector<int> s(2 * 1000 + 1, 0);  
  vector<int> d(2 * 1000 + 1, 0);

  while(m--){
    int x,y;
    cin>>x>>y;
    ++s[x+y];
    ++d[1000 + x - y]; 
  }

  int counter=0;

  for(int p=0; p <2 * 1000 + 1;p++){
      counter += s[p] * (s[p]-1) / 2;
      counter += d[p] * (d[p]-1) / 2;
  }


  cout<<counter;
  return 0;
}