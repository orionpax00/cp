#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	set<string> se;
	map<string, int> m;
	for(int i =0; i < n; i++){
		string s; cin >> s;
		m[s]++;
		se.insert(s);
	}

	vector<pair<int, string> > v;
	for(auto x: se){
		v.push_back({m[x], x});
	}

	sort(v.rbegin(), v.rend());

	for(auto x: v) cout << x.second << " ";


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
