#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n, m; cin >> n;

	map <int, int> ma;
	for(int i = 0; i < n; i++){
		int t; cin >> t; ma[t]++;
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		int t; cin >> t; ma[t]--;
	}

	for(auto x : ma){
		if(x.second < 0) cout << x.first << " ";
	}
	

  return 0;
}
