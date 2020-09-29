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
		int counter = 0;
		while( (n&1) == 0){
			counter++;
			n >>= 1;	
		}
		int l = n_ - pow(2, counter) + 1;
		int r = n_ + pow(2, counter) - 1;
		cout << l << " " << r << "\n";
	}
	

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
