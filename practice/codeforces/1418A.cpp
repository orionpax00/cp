#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int x,y,k; cin >> x >> y >> k;

		int ans = ((k * (1+y) - 1 ) + x - 2) / (x - 1);
		cout << ans + k << "\n";
	}	



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
