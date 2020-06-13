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
		int ans=0;
		cin>>ts;
	
		if(ts&1){
			ans = ts/2; 		
		}else{
			long long tjs = (ts - 2)/2;
			long long divideby = 1; 
			while(ts%2 == 0){
				divideby++;
				ts /= 2;	
			}
			ans = tjs/divideby;
		}

		cout<<ans<<"\n";

	}   

  return 0;
} 
