#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		long long ts;
		long long ans=0;
		cin>>ts;
	
		if(ts&1){
			ans = ts/2; 		
		}else{
			long long tans = ts/2-1;
			while(ts%2 == 0){
				ts /= 2;
				tans /= 2;
			}
			ans = tans;
		}
		cout<<ans<<"\n";

	}   

  return 0;
} 
