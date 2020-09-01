#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >>n  >> m;
	vector<int> v1(n), v(m);
	
	for(auto& x : v1) cin >> x;
	for(auto& x : v) cin >> x;

	sort(v1.rbegin(), v1.rend());
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for(int i = 0 ; i < m; i++){
		ans += v1[i] * v[i];
	}

	for(int x : v1) ans += x;

	cout << ans;


    

  return 0;
}
