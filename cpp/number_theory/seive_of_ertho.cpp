/*
*   Author - Durgesh(orionpax00)
    Some legends are told
        Some turn to dust or to gold
            But you will remember me
                Remember me for centuries...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds; 
#define fr(i,o,n) for(int i = o; i <= n; i++)
#define rep(i,o,n) for(int i = o; i < n; i++)
#define replli(i,o,n) for(long long int i = o; i < n; i++)
#define trav(x,a) for(auto &x : a)
#define lli long long int
#define mod 1000000007
#define pb push_back
#define local false

vector<int> primeNum(int A) {
    
    vector <bool> prime[A+1]; 
    memset(prime, true, sizeof(prime));
  
    for (int p=2; p*p<=A; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=A; i += p) 
                prime[i] = false; 
        } 
    }
    
    return prime;
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    primeNum(6);
    
    return 0;
}
// 