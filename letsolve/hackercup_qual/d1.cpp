#include <bits/stdc++.h>
#define int long long

int MAXN = LLONG_MAX - 1e9;

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t; cin >> t;
	int ci = 1;
	while(t--){
		
		int n, k ; cin >> n >> k;
		vector<int> v(n + 1);
		v[0] = 0;
		for(int i = 0 ; i < n ; i++) cin >> v[i + 1];
		
		vector<int> dp(n+1, MAXN);
		for(int i = 1; i <= min(k+1, n) ; i++) dp[i] = 0;
		for(int i = k + 2; i <= n ; i++){
			for(int j = 1 ; j <= min(k, n) ; j++){
				if(v[i - j] == 0) {
					continue;
				}
				dp[i] = min(dp[i], dp[i-j] + v[i - j]);
			}
		}
		cout << "Case #" << ci << ": "; ci++;
		if(dp[n] == MAXN) cout << -1 << "\n";
		else cout << dp[n] << "\n";
	}

  return 0;
}
