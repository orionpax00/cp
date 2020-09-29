#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);

		int t = b - a;
		int ans = 0;
		for(int i = 10 ; i > 0; i--){
			while(t >= i){
				ans += t/i;
				t -= (t/i) * i;
			}
		}
		
		cout << ans << "\n";
	}	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
