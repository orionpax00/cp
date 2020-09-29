#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
	if(a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}


void solve(){
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int> (2));
	
	for(auto& x : v) cin >> x[0] >> x[1];

	sort(v.begin(), v.end(), cmp);
	
	vector<vector<int>> ans;
	int fir = v[0][0];
	int last = v[0][1];
	for(int i = 1; i < n; i++){
		if(last < v[i][0]){
			ans.push_back({fir, last});
			fir = v[i][0];
			last = v[i][1];
		}else{
			last = v[i][1];
		}
	}

	ans.push_back({fir, v[n-1][1]});

	for(auto x : ans) cout << x[0] << " " << x[1] << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
