//0/1 knapsack
template<typename T>
int knap(vector<int>& W, vector<T>& C, int Wt){
	int n = W.size();
	vector<T> dp(Wt + 1);
	for(int i = 0; i < n; i++){
		for(int j = Wt - W[i]; j >= 0; i--){
			dp[j+W[i]] = max(dp[j + W[i]], dp[j] + C[i]);
		}
	}

	return dp[Wt];
}

//naive 2d approach
template<typename T>
int knap(vector<int>& W, vector<T>& C, int Wt){
	int n = W.size();
	vector<vector<T>> dp(n + 1, vector<T>(Wt + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= Wt; j++){
			if(j >= W[i- 1]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + C[i - 1]);
			else dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][Wt];
}
