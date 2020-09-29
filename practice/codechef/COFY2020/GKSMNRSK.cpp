#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		map<int, int> m;
		for(int i = 0; i < n ; i++){
			int t; cin >> t;
			m[t]++;
		}

		int m_ = 0;
		for(auto x : m) m_ = max(m_, x.second);
	
		if(m_ > n/2) cout << m_ << "\n";
		else cout << (n+1)/2 << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
