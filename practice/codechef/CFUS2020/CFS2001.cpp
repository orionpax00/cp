#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int tt; cin >> tt;
	while(tt--){
		int a, d, k, n, inc; cin >> a >> d >> k >> n >> inc;
		int ans = a;
		for(int i =1; i < n; i++){
			ans += d;
			if((i + 1)%k == 0) d +=inc;
		}	

		cout << ans << "\n";		

	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
