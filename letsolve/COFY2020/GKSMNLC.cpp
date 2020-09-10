#include <bits/stdc++.h>
#define int long long

using namespace std;

bool solve(vector<int>& v,int n, int k){
	if(k == 0) return true;
	if(n == 0) return false;

	if(v[n-1] > k) return solve(v, n - 1, k);

	return solve(v, n-1, k) || solve(v, n-1, k - v[n-1]);
}




int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int tt; cin >> tt;
	while(tt--){
		int n, k; cin >> k >>  n;
		vector<int> v(n); for(int& x : v) cin >> x;

		cout << solve(v, n , k) << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
