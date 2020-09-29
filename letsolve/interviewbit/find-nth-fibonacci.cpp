#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

void solve(){
	int n; cin >> n;

	int a = 1; int b = 1;
	int ans = 1;
	for(int i = 3 ; i <= n; i++){
		ans = (a+b)%mod;
		a = b;
		b = ans;
	}

	cout << ans;

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1;// cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
