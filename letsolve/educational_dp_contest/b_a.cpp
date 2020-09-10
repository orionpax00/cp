#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k; cin >> n >> k;
 	vector<int> v(n); for(int& x : v) cin >> x;

	vector<int> dp(n,1000000000);
	
	dp[0] = 0;

	for(int i = 1 ; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(i-j >= 0) dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i-j]));
		}
	}

	cout << dp[n-1];


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
