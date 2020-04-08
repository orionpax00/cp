//	Every elemnt apperat twice except onece find that
//	array XOR
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int x, sum=0;
  while(cin>>x){
    sum ^= x;
  }
  cout<<sum;

  return 0;
} 