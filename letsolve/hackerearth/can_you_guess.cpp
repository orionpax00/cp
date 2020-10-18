#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	long long ans = 0;
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			ans += i;
			if(i != 1 && i != n/i)
				ans += n/i;
		}
	}

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
