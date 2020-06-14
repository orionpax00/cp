#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t; cin>>t;
	while(t--){
		int n ; cin >> n ;
		int left = 0;
		if(n%2 == 0){
		for(int i = 0 ; i < n ; i++){
			if(i%2 == 0){
				int tleft;
				for(int j = left+1; j <= left+n; j++){
					cout<<j<<" ";
					tleft = j;
				}
				cout<<"\n"; left=tleft;	
			}else{
				int tleft;
				for(int j = left+1; j <= left+n; j+=2){
					if(j+1<=left+n)cout<<j+1<<" " <<j<<" ";
					else cout<<j;
					tleft = j+1;
				}
				cout<<"\n"; left = tleft;
			}
		}
		}else{
			for(int i = 0; i < n ; i++){
				left = i*n;
				for(int j = 1; j <= n ; j++){
					cout<<j+left<<" ";
				}cout<<"\n";
			}	
		}
		}    

  return 0;
}
