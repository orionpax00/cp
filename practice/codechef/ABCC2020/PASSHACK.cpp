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
		int n_ = n;
		int t = 0;
		int c = 0;
		while(n_){
			t += 2 * pow(10, c);
			c++;
			n_ /= 10;
		}
		if(t > n) t /= 10;
		cerr << t << "\n";
		cout << n - t << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
