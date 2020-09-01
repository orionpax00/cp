#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int n ; cin >> n;
	int min_ = INT_MAX;
	int ans = INT_MIN;
	int t; cin >> t;
	min_ = t;
	for(int i = 1 ; i < n; i++){
		int t; cin >> t;
		ans = max(min_ - t, ans);
		min_ = min(min_, t);
	}

	cout << ans;

  return 0;
}
