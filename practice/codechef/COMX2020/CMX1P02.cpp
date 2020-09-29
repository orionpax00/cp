#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int tt; cin >> tt; 
	while(tt--){
		int n; cin >> n;
		int ans = 1;
		for(int i = 0; i < n; i++){ int t; cin >> t; ans *= t;}	
		int r; cin >> r; 
		cout << ans + r << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
