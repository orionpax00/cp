#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t ; cin >> t;
 	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int> v(n);
		vector<int> vl(n);
		for ( int i = 0 ; i < n ; i++){	
			int t; cin >> t; v[i] = t;
		}
	
	  sort(v.begin() , v.end());
		int ans = 0;
		
		for ( int i = 0 ; i < n ; i++) vl[i] = v[i];

		auto up1 = lower_bound(v.begin(), v.end(), x);
		int u1 = up1 - v.begin();
		//if(u1 == 0) u1 = 1;

		while(true){
			if(u1 >= n) {
					for(int i = n-1 ; i >= 0 ; i--){ 
						if (vl[i] > 0 ){
							///cout << i << " " << vl[i] <<"yehhh\n";
						  while(vl[i] > x){
								x *= 2;
								ans++;
							}
							x = v[i]*2;
							ans++;
						}
					}
					break;
			}
			while( x < v[u1]) {
				if(x/2 < v[u1 -1]) break;
				ans++;  x *= 2;
			} 
			if(vl[u1 - 1] * 2 >= x){
				vl[u1 - 1] = 0;
				x = v[u1 - 1]*2;
				ans++;
			}else{  
				vl[u1] = 0; 
				x = v[u1]*2;
				u1++;
				ans++;
			} 
    }
		cout << ans << "\n";
	} 
    

  return 0;
}
