#include <bits/stdc++.h>
#define int long long

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
		for ( int i = 0 ; i < n ; i++){	
			cin >> v[i];
		}
	  sort(v.begin() , v.end());
		auto up = upper_bound(v.begin(), v.end(), x);
		int u = up - v.begin();
		int ans = 0;
		for(int i = u ; i < n ; ++i){
			if(v[i-1] == x) {
				x *= 2;
				u--;
			}else{
				while(x < v[i]){
					x *= 2;
					ans++;
				}
				ans++;
				x = v[i]*2;
			}
		}
		ans += u;
		cout << ans << "\n";
	} 
    

  return 0;
}
