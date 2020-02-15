#include <bits/stdc++.h>

using namespace std;

int modulo(int n, int k){
    int result=1;
    if(n>=k) return 0;
    else{
        for(int i=2; i<=n;++i) {
            result *= i%k;
        }
    }
    return result%k;
}

int seive_of_eresthonesis(int n){
    int isPrime[n+1];
    memset(isPrime,1,sizeof(int)*(n+1));
    isPrime[0] = isPrime[1] =0;
    int c=0;
    for(int i=2; i<=sqrt(n);i++){
        if(isPrime[i]){
            c++;
            for(int j=i*2; j<=n; j+=i){
                isPrime[j] =0;
            }
        }else continue;
    }
    for (int i=sqrt(n)+1; i<=n;++i){
        if(isPrime[i]) c++;
    }
    return c;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int M=1000000123, n,k;
    cin>>n>>k;

    int x= seive_of_eresthonesis(n);
    if(x>k)cout<<0;    
    int ans=1;
    int ans1 = int(pow(modulo(10,M),2))%M;
    ans *= modulo(n,M);
    ans *= modulo(x, M);
    ans *= modulo(k, M);
    ans *= modulo(n-k, M);
    ans *= modulo(x-k, M);
    ans %= M;
    cout<<ans1<<" :ans1\n";
    cout<<ans<<" :ans\n";

    int ans2 = (ans1 + ans)%M;
    cout<<ans2;
}
