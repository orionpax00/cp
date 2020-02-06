#include <bits/stdc++.h>

using namespace std;

int sumDigFac(int n){
  int ans[6000];
  ans[0] = 1;
  int ans_size = 1;
  for(int i=2;i<=n;++i){
   int carry=0;
   for(int j=0; j<ans_size; ++j){
     int prod = ans[j]*i + carry;
     ans[j] = prod%10;
     carry = prod/10;
   }
   while(carry){
     ans[ans_size] = carry%10;
     carry=carry/10;
     ans_size++;
   } 
  }
  int sum = 0;
  for(int i=0; i<ans_size; ++i) sum += ans[i];
  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n = 2000;
  cout<<sumDigFac(n);
  return 0;
}