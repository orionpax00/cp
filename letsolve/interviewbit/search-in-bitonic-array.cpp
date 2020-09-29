#include <bits/stdc++.h>
using namespace std;

void solve(){	
	int n, k; cin >> n >> k; vector<int> v(n); for(int& x: v) cin >> x;

	int l = 0, r = n - 1;
	int mid;
	while(l < r){
		mid = (l + r)/2;
		if(v[mid] == k) break;
		else if(v[mid] 
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
