#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int t;
    cin>>t;
    while(t--){
        int n, sum=0,counter=0;
        cin>>n;
        bool done=false;
        for(int i=0; i<n;i++){
            int temp;
            cin>>temp;
            if(i == sum && !done){
                if(temp==0){cout<<-1<<"\n";done=true; continue;}
                counter++;sum+=temp;
                if(sum>=n-1) {cout<<counter<<"\n"; done=true;}
            }
        }
    }
    return 0;
}