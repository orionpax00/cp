#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; 
	vector<int> v(n);  for(int& x: v) cin >> x;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if((v[i] & v[j]) >= (v[i] ^ v[j])) ans++;
		}
	}

	cout << ans << "\n";


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
