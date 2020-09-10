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
		vector<int> v(n + 1);
	 	for(int i = 1 ; i <= n ; i++){
			int t; cin >> t;
			v[i] = v[i-1] + t;
		}	

		int m_ = INT_MAX;
		for(int x : v) m_ = min(m_, x);

		cout << abs(m_) << "\n";
	}
    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
