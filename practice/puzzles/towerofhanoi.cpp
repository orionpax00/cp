#include <bits/stdc++.h>
using namespace std;

// f: from rod
// t: to rod
// a: auxilary rod
void tofh(int n, int f, int t, int a){
  if(n==1){
    cout<<n<<"***"<<f<<"--->"<<t<<"\n";
    return;
  }
  tofh(n-1,f,a,t);
  cout<<n<<"***"<<f<<"--->"<<t<<"\n";
  tofh(n-1,a,t,f);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  tofh(4,0,1,2);
  return 0;
}