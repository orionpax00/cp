#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	int m_ = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		m_ = max(m_, v[i]);
	}

	for(int i = 2; i < m_; i++){
		int t = v[0]%i;
		bool ok = true;
		for(int j = 1; j < n; j++){
			if(v[j]%i != t){ok = false; break;}
		}

		if(ok) cout << i << " ";
	}

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1;// cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
