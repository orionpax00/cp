#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0; cin >> n;
	int max_ = INT_MIN;
	for(int i = 0 ; i < n; i++){
		int t; cin >> t;
		max_ = max(max_, t);
		ans += max_ - t;
	}
    
	cout << ans;

  return 0;
}
