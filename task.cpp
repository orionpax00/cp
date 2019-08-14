/*
    Author - Durgesh(orionpax00)
*/

#include <bits/stdc++.h>

using namespace std;

#define fr(i,o,n) for(int i = o; i <= n; i++)
#define rep(i,o,n) for(int i = o; i < n; i++)
#define trav(x,a) for(auto &x : a)
#define lli long long int
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector < lli > v;
    rep(i,0,n){
        lli x ;
        cin>>x;
        v.pb(x);
    }

    
    sort(v.begin(),v.end());

    

    if ( n % 2 == 0){
        for(int i = 0; i < n ; i += 2){
            v[i+1] -= v[i];
            v[i] -= v[i];

        }
    }
    else{
        for(int i = 0; i < n-1 ; i += 2){
            v[i+1] -= v[i];
            v[i] -= v[i];

        }
    }

    rep(i,0,n-1){
        while(v[i] > 0 && v[i+1] > 0){
            --v[i+1];
            --v[i];
        }
    }


    int sum  = accumulate(v.begin(), v.end(), 0);

    if(sum == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    

    return 0;
}