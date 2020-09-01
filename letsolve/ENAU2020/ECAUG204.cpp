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
		bool ok = true;
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t;
			if(m.count(t)) ok = false;
			m[t]++;
		}	

		if(ok) cout << "Yes\n";
		else cout << "No\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
