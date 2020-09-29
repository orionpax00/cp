#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, q; cin >> n >> q;
	vector<int> v(n); for(int& x : v) cin >> x;
	long long ans = 0;
	bool flag = true;
	for(int i = 1; i < n; i++){
		if(flag){
			if(v[i] < v[i-1]) ans += v[i-1], flag ^= 1;
		}else{
			if(v[i]> v[i-1]) ans -= v[i-1], flag ^= 1;
		}
	}
	if(flag) ans += v[n-1];
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
