#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

// long long MAXN = 1000000000;
long long factorial[1000000000];


int binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k]) % m * inverse(factorial[n - k]) % m;
}

long long modpow2(long long n){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans = (ans * 2)%m;
  }
  return ans;
}

int main(){
    long long n,a,b;
    cin>>n>>a>>b;
    factorial[0] = 1;
    for (long long i = 1; i <= 1000000000; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }
    long long ans = modpow2(n) - binomial_coefficient(n,b) - binomial_coefficient(n,b) - 1;
    cout<<ans;
}

// 4 -> 2^4-1 = 15 - 4 - 4 = 7