//	Binary Exponentiation
//	Maths algebra
#include <bits/stdc++.h>
using namespace std;
//My implementation {worst but working}
// long long int be(int a, int b){
//   long long ans = 1;
//   int po=1;
//   int ta=1;
//   while(po <= b){
//     int mpo = po*(__builtin_popcount(b & ta));
//     ta <<= 1;
//     cout<<mpo<<"\n";
//     ans *= pow(a, mpo);
//     po *= 2;
//   }

//   return ans;
// }

long long int be(long long int a, long long int b){
  long long int res=1;
  while(b>0){
    if(b&1) res *= a;
    a *= a;
    b>>=1;
  }
  return res;
}

long long int bem(long long int a, long long int b, long long int m){
  long long int res=1;
  while(b>0){
    if(b&1) res = (res%m) * (a%m);
    a *= a;
    b>>=1;
  }
  return res%m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int a,b; cin>>a>>b;
  long long int ans = be((long long)a,(long long)b);
  long long int ans = pow(a,b); //builtin function
  cout<<ans;
  
  return 0;
}

// Application
// 1. Compute x^n (mod m) if you compute using pow(x,n) then it will 
// a very large value to fit in any datatype so using be implementation
// and modulo properties it can be achived.


// using be funtion --> TotalSeconds : 0.0338038
// using builtin pow function --> TotalSeconds : 0.0301265