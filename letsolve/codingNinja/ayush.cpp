#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(int k ,vector<int>& v){
		sort(v.begin(), v.end());
		int n = v.size();
		int left = k/2;
		int right = n - (k+1)/2;
		int ans = 0;
		ans += abs(v[left] - v[right - 1]);
		int	min_ = INT_MAX;
		for(int i = left; i < right - 1; i++) 
			min_ = min(min_, abs(v[i] - v[i+1]));

		ans += min_;
		
		left = (k+1)/2;
		right = n - k/2;
		int ans2 = 0;
		ans2 += abs(v[left] - v[right - 1]);
		min_ = INT_MAX;
		for(int i = left; i < right - 1; i++) 
			min_ = min(min_, abs(v[i] - v[i+1]));

		ans2 += min_;

		return min(ans, ans2);
							
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n, k; cin >> n >> k;
	vector<int> v(n); for(int& x : v) cin >>x;

	cout << solve(k ,v );


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
