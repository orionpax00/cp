#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n); for(int& x : v) cin >> x;
		reverse(v.begin(), v.end());
		
		for(int x : v ) cout << x << " ";
		cout << "\n";
	}	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
