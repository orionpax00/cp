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
		vector<int> v(n);
		for(int& x : v) cin >> x;
		if(n == 1) cout << "YES\n";
		else{
			bool ok = true;
			sort(v.begin(), v.end());
			int prev = v[0];
			for(int i = 1; i < n; i++){
				if(v[i] - prev > 1) ok = false;
				prev = v[i];
			}

			if(ok) cout << "YES\n";
			else cout << "NO\n";
		}	

	}
	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
