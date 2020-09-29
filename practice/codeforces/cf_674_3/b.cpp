#include <bits/stdc++.h>
using namespace std;

bool isok(vector<vector<int>> v){
	if(v[1][0] == v[0][1]) return true;
	return false;
}

void solve(){
	int n, m; cin >> n >> m;
	bool ok = false;
	for(int i = 0; i < n; i++){
		vector<vector<int>> v(2, vector<int>(2));
		cin >> v[0][0];
		cin >> v[0][1];
		cin >> v[1][0];
		cin >> v[1][1];

		if(isok(v)) ok = true;
	}

	if(m%2 != 0) cout << "NO\n";
	else if(!ok) cout << "NO\n";
	else cout << "YES\n";

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
