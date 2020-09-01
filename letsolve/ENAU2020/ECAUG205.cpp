#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n,k; cin >> n >> k;
		vector<int> v(n);
		int min_ = INT_MAX;
		for(int i = 0 ; i < n; i++){
			int t; cin >> t;
			v[i] = t;
			min_ = min(min_, t);
		}

		bool ok = false;

		while(min_ > 0){
			int k_ = 0;
			for(int i = 0 ; i < n; i++){
				k_ += v[i]/min_;
			}
			if(k_ >= k) {
				cout << min_ << "\n";
				ok = true;break;
			}
			min_--;
		}

		if(!ok) cout << -1 << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
