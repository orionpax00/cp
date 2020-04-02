#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0; i<n;++i){
      cin>>a[i];
    }
		bool isyes=false;
		int ans;
		for(int i=n-1;i>=0;i--){
			if(p%a[i] != 0) {ans = i;isyes=true;break;}
		}
		if(isyes){
      cout<<"YES";
      for(int i=0; i<n;++i){
        if(i == ans) cout<<" "<<p/a[i]+1;
        else cout<<" "<<0;
      }
			cout<<"\n";
    }else{
			cout<<"NO\n";
		}
  }
  
  return 0;
}