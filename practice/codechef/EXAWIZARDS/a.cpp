#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n);

	for(auto& x : v) cin >> x.second >> x.first;

	sort(v.rbegin(), v.rend());
	int ans = 0;
	set <int> s;
	vector<pair<int, int>> auxv;
	int c = 0;
	for(int i = 0 ; i < n	&& c < k; i++){
		int t = s.size();
		if((t+1)*(t+1) - t * t < v[i].first){
	    ans += v[i].first;
			s.insert(v[i].second);
			c++;
		}else{
			auxv.push_back(v[i]);
		}	
	}
	int i = 0;
	while(c < k){
		ans += auxv[i].first;
		i++; c++;
	}

	ans += s.size() * s.size();

	cout << ans << "\n";

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
