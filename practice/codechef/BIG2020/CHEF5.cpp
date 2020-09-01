#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n ; cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0 ; i < n; i++ ){
		int t; cin >> t;
		v[i].first = t;
		v[i].second = i;
	}
	int ans = 0;
	sort(v.begin(), v.end());
	for(int i = 0 ; i < n; i++){
		if(v[i].second == i) continue;

		else
			swap(v[i], v[v[i].second]);
    if(i == v[i].second) i--;
		ans++;
	}

	cout << ans;

  return 0;
}
