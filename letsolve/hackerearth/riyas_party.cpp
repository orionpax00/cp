// wrong solution


#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

void solve(){
	long long n; cin >> n;
	if(n == 1) {
					cout << 1 <<"\n";
				 return;
	}
	if(n==2){
		cout << 2 << "\n";
		return;
	}
	
	long long ans = n + (n + 1) * 3;
	cout << ans%MOD << "\n";	
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
