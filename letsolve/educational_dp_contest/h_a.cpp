#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = 1e9 + 7;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w; cin >> h >> w;
	vector<vector<int>> v(h, vector<int>(w,0));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char t; cin >> t;
			if(t == '.') v[i][j] = 1;	
		}
	}	

	vector<vector<int>> dp(h, vector<int>(w, 0));
	dp[0][0] = 1;
	for(int i = 1; i < w; i++) if(v[0][i]) dp[0][i] = dp[0][i-1] && 1;
	for(int i = 1; i < h; i++) if(v[i][0]) dp[i][0] = dp[i-1][0] && 1;

	for(int i = 1; i < h; i++){
		for(int j = 1; j < w; j++){
			if(v[i][j]){
				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
			}
		}
	}
	cout << dp[h-1][w-1];


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
