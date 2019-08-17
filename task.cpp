/*
    Author - Durgesh(orionpax00)
*/

#include <bits/stdc++.h>
#include <algorithm>  

using namespace std;

#define fr(i,o,n) for(int i = o; i <= n; i++)
#define rep(i,o,n) for(int i = o; i < n; i++)
#define replli(i,o,n) for(long long int i = o; i < n; i++)
#define trav(x,a) for(auto &x : a)
#define lli long long int
#define M 1000000007
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int n,m,k;
    cin>>n>>m>>k;

    vector < int > v; 
    rep(i,0,n){
        rep(j,0,m){
            v.pb((i + 1) * (j+1));
        }
    }

    sort(v.begin(), v.end());

    cout<<v[k-1]<<"\n";

    return 0;
}