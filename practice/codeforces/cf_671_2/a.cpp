#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int c, n; cin >> c >> n;
		vector<int> v(c);
		
		while(n){
			v.push_back((n%10));
			n /= 10;
		}

		
    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
