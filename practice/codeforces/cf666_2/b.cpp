#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;	
	vector<int> v(n);

	for(int& x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = LLONG_MAX;
	for(int i = 1 ; i < 100001; i++){
		int v1 = 0;
		int t = 1;
		for(int j = 0; j < n; j++){
			v1 += abs(t - v[j]);	
			if(v1 > 1e14) break;
			t *= i;
		}
		ans = min(ans, v1);
	}
	cout << ans;

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
