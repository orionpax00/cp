void edit_dis(vector<vector<int>>& dp, string& a, string& b){

	int n = a.length();
	int m = b.length();

	for(int i = 0; i <= n ; i++) {
		for(int j = 0; j <= m; j++){
			if(i == 0) dp[i][j] = j;
			else if(j == 0) dp[i][j] = i;
			else if(a[i-1] == b[i-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
		}
	}

	//memory opimized //in that case dp should be dp[2][len of b + 1]
	/*
	iota(dp[0].begin(), dp[0].end(), 0);
	for(int i = 1; i <= n; i++){
		int bi = i&1;
		for(int j = 0; j <= m; j++){
			if(j == 0) dp[bi][j] = i;
			else if(a[i - 1] = b[j - 1]) dp[bi][j] = dp[bi ^ 1][j - 1];
			else dp[bi][j] = 1 + min({dp[bi ^ 1][j], dp[bi][j-1], dp[bi ^ 1][j - 1]});
		}
	}

	// result would be dp[n&1][m] (that is dp[bi][m]

	*/

}
