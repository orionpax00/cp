#include <bits/stdc++.h>
using namespace std;

int MOD = 1e7+9;


void solve(){
	long long n; cin >> n;
	long long ans = 0;
	n -= 1;
	long long t1 = (n * (n + 1))%MOD;
	long long t2 =  (2*n + 1)%MOD;
	
	ans = (t1 * t2) % MOD;
	ans /= 6;
	n++;
	long long ans2 = ((n * (n - 1))/2 + n - 1)/n;

	ans2 %= MOD;
	ans2 *= ans2;
	ans2 %= MOD;
	ans2 *= n;
	ans2 %= MOD;

	cout << ans2 << " " << ans << "\n";
		
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
