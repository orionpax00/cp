#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(int a, int b, int x , int y , int n){
	int t = min(a - x, n);
	a -= t;
	n -= t;
	b -= min(b - y, n);

	return a*b;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int a, b, x, y, n; cin >> a >> b >> x >> y >> n;
    
		cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n) ) << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
