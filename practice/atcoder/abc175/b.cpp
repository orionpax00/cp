#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int i =0; i < n; i++) cin >> v[i];
	int ans = 0;
	for(int i = 0; i < n ; i++)
		for(int j = i + 1 ; j < n; j++)
			for(int k = j + 1; k < n; k++)
				if(v[i] + v[j] > v[k] && v[i] != v[j] && v[i] != v[k] && v[j] != v[k] && v[i] + v[k] > v[j] && v[j] + v[k] > v[i]) ans++;

	cout << ans;

  return 0;
}
