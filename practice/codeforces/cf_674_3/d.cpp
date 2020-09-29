#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; 
	vector<int> v(n); for(int& x: v) cin >> x;	

	vector<int> pref(n+1);
	for(int i= 1; i <= n; i++){
		pref[i] += pref[i-1] + v[i - 1];
	}
	int j=1, i = 0;
	int ans = 0;
	while(j < n && i < n){
		if(i != j && pref[j] - pref[i] == 0) {ans++ ;j++;}
		else if(pref[j] - pref[i] < 0) j++;
		else i++;
		if(i > j ) j = i + 1;
	}

	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
