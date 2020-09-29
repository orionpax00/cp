#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n ; cin >> n;
	vector<int> v(n);
	for(int& x: v) cin >> x;
	int p = n -1;
	while(p > 0&& v[p - 1] >= v[p]) p--;	
	while(p > 0&& v[p - 1] <= v[p]) p--;	
	cout << p << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
