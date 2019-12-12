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





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int durgesh = 00;

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    string s ;
    cin>>s;
    cout<<s;

    auto start = chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    
    if (local){
        
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << "\n\n\nExecution Time: "
            << duration.count() << " ms" << endl; 

        int memory = (sizeof(durgesh)) / 1024.0;
        cout<<"Memory usage: "<<memory<<" kb"<<endl;
    }

    return 0;
}
// 