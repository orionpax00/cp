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

//string binary = bitset<8>(128).to_string();

double findMedian(const vector <int> &A, const vector <int> &B){
    

    int m = A.size() -1;
    int n = B.size() -1;
    

    int al = 0;
    int ar = m;

    int i, j;
    if(m, n > 0){
        while(al <= ar){
            i = (al + ar)/2;
            j = (m + n - 1 )/2 - i;
            
            if ( A[i] <= B[j+1] && A[i+1] >= B[j]){
                if ((m+n)%2 ==0 ) return (max(A[i], B[j]) + min(A[i+1], B[j+1])) / 2;
                else return min(B[j+1], A[i+1]);
            }
            else{
                if(A[i+1] < B[j]) { al = i+1;}
                else if(A[i] > B[j+1]) { ar = i;}
            }
        } 
    }
    else{
        if(m>0)
            return (A[int(n/2)]+A[int(n+1/2)])/2;
        if(n>0)
            return (B[int(n/2)]+B[int(n+1/2)])/2;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector < int> A = {16, 19};
    vector < int> B = {-46, -15, -9, -7, -2, 24, 40};

    cout<< findMedian(A, B)<<endl;

    return 0;
}
