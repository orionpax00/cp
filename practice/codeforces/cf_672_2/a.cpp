#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(int& x: v) cin >> x;
	set<int> s;
	for(int x : v) s.insert(x);

	if(is_sorted(v.begin(), v.end())) cout << "YES\n";
	else if(is_sorted(v.begin(), v.end(), greater<int>()) && (int)s.size() == n) cout << "NO\n";
	else cout << "YES\n";

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
