#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(vector<pair<int, int >>& a){	
	
	vector<vector<int> > dp(n+1, vector<int>(2, 0));

	for(int i = 1 ; i <= n; i++){
		dp[i][0] = a[i-1] + dp[i][1];
		dp[i][1] = 


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    
	cout << solve(a, b);



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
