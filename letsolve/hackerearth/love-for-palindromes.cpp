#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;
	vector<vector<int>> v(26);
	int n = s.length();
	for(int i = 0; i < n; i++){
		v[s[i] - 'a'].push_back(i);
	}
	bool ok = false;
	int ans = INT_MAX;
	for(auto x: v){
		if(x.size() > 1){
			int k = x.size();
			for(int i = 0; i < k - 1; i++){
				if(x[i+1] - x[i] == 2) ans = min(ans, 0);
				else ans = min(ans, (x[i+1] - x[i] - 1));
			}
			ok = true;
		}
	}

	if(!ok) cout << -1 << "\n";
	else cout << ans << "\n";


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; 
	cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
