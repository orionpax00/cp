#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(int& x : v) cin >> x;
	sort(v.begin(), v.end());
	vector<int> pref(n+1) for(int i = 1; i <= n; i++) pref[i] = v[i] + pref[i - 1];


	while(i < j){


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; ///cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
