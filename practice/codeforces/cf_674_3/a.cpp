#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x; cin >> n >> x;
	int ans = max(0, n - 2 + x - 1)/x + 1;
	cout << ans << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
