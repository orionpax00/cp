/*
    Author - Durgesh(orionpax00)
*/

#include <bits/stdc++.h>

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

    string s ;
    cin>>s;

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

    return 0;
}