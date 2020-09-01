#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 	
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >>k;
		int m_ = INT_MIN;
    int ans = 0; int cw = 0;
		vector<int> v(n); for(auto& x: v) cin >> x;
		for(int i = 0 ; i < n;){
			int t = v[i]; m_ = max(m_, t);
			cw += t;
			if(cw > k){
				ans++; cw = t;
			} 

			i++;
		}

		if(m_ > k) cout << -1 << "\n";
		else cout << ans + 1 << "\n";
	}


  return 0;
}
