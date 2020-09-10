#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(3));    
	for(auto& x : v) cin >> x[0] >> x[1] >> x[2] ;

	vector<vector<int>> dp(2, vector<int>(3));
	
	for(int i : {0,1,2}) dp[0][i] = v[0][i];

	for(int i = 1; i < n; i++){
		for(int t : {0,1,2}) dp[1][t] = 0;

		for(int j : {0, 1, 2}){
			for(int k : {0, 1, 2}){ 
				if(j != k) dp[1][j] = max(dp[1][j], dp[0][k] + v[i][j]);
			}
		}
		
		for(int t : {0,1,2}) dp[0][t] = dp[1][t];
	}
	
	cout << max({dp[0][0], dp[0][1], dp[0][2]});
	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
