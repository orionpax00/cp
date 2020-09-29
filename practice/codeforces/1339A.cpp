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
		int cm = INT_MAX;
		int om = INT_MAX;

		vector<int> c(n), o(n);

		for(int i = 0; i < n; i++) {cin >> c[i];	cm = min(cm, c[i]);}
		for(int i = 0; i < n; i++) {cin >> o[i]; om = min(om, o[i]);}	
    
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += max(o[i] - om, c[i] - cm);
		}

		cout << ans << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
