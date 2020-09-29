#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	int tt; cin >> tt;
	while(tt--){
		int n ; cin >> n;
		int ans = 0;
		while(n--){
			int t; cin >> t;
			if( (t&1) == 0) ans += t;
		}

		cout << ans << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
