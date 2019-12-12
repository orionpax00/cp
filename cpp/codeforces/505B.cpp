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
#define local true
#define endl '\n'

struct Edge {
    int s;
    int e;
    int c;
};

int main()
{
    if (local){
        cout<<"Compilation done...\nenter value..."<<endl;
    } 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int durgesh = 0;

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;

    set < int > V;

    Edge e[m];

    rep(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        V.insert(u);
        V.insert(v);

        e[i].s = u;
        e[i].e = v;
        e[i].c = c;

    }
    int q,ut,vt;
    cin>>q;
    while (q--){
        int counter=0;
        cin>>ut>>vt;
        rep(i,0,m){
            bool f = true;
            int numc = 0;
            vector < int > col;
            rep(j,0,numc){
                if(col[j] == e[i].c) f = false;
            }
            if ((ut == e[i].s || ut == e[i].e) && (vt == e[i].s || vt == e[i].e) && f){
                counter++;
                numc++;
                col.pb(e[i].c);
            }
        }
        cout<<counter<<endl;
    }


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