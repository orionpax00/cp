#include <bits/stdc++.h>
#define int long long

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n);
		int max_ = INT_MIN;
		for(int i = 0 ; i < n ; i++){
    	int t; cin >> t;
			max_ = max(t, max_);
			v[i] = t;
		}
		sort(v.rbegin(), v.rend());
		vector<pair<int, int>> vn(n);
		vn[0].first = v[0];
		vn[0].first = v[0];
		
		for(int i = 1; i < n; i++){
			vn[i].first = __gcd(vn[i-1].first, v[i]);
			vn[i].second = v[i];
		}

		sort(vn.rbegin(), vn.rend(), comp);

		for(auto x : vn) cout << x.second << " " ;
		cout << "\n";
	}



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
