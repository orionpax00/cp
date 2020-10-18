#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n; cin >> n;
	if(n==1){cout << 1 << "\n"; return;}
	long long ans = 2;
	for(int i = 2; i*i <= n; i++){
		if(n%i==0){
			ans += 2;
			if(i == n/i) ans--;
		}
	}
//	int t = sqrt(n)*sqrt(n);

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
