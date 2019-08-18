/*
    Author - Durgesh(orionpax00)
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
#define time false

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    string s ;
    cin>>s;
    auto start = chrono::high_resolution_clock::now();
    
    int t;
    cin >> t;
    int n = s.length();

    int arr[100001];

    rep(i,0,n){
        if(s[i] == s[i+1]) arr[i+1] = arr[i] + 1;
        else arr[i+1] = arr[i];
    }
    
    while(t--){  
        int l,r;
        cin>>l>>r;
        cout<<arr[r-1] - arr[l-1]<<endl;       
    }


    if (time){
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << "\n\n\nTime taken by function: "
            << duration.count() << " ms" << endl; 
    }

    return 0;
}