#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n, k ; cin >> n >> k;
		vector<int> v(n);
		vector< vector<int> > dp(n+1, vector<int>(103));

		for(int i = 0; i < n ; i++){
			cin >> v[i];
		}

		for(int i = 1; i <= n; i++) {
			for(int j = 0 ; j < 103; j++){
				dp[i][j] = dp[i-1][j];
			}
			dp[i][v[i - 1]]++;
		}
	
		vector<int> cost(n+1, 1000000000);
		cost[0] = 0; cost[1] = k;
		for(int i = 2; i <= n ; i++){
			for(int j = 1; j <= i; j++){
				int c = 0;
				for(int k1 = 1; k1 < 101; k1++){
					c += (dp[i][k1] - dp[j-1][k1] > 1) * (dp[i][k1] - dp[j-1][k1]);
				}
				c += cost[j-1] + k;
				cost[i] = min(cost[i], c);  
			}
		}
		cout << cost[n] << "\n";
	}
 

  return 0;
}
