#include <bits/stdc++.h>
#define int long long

using namespace std;

int dig_sum(int n){
	int ans = 0;
	while(n){
		ans += n % 10;
		n /= 10;
	}
	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n, s; cin >> n >> s;
		int ans = 0;
		int counter = 0;
		while(dig_sum(n) > s){
			int t = (10 - n%10);
			n += t;
			ans += t * pow(10, counter);
//			cerr << counter << " " << t << " " << n << " " << ans << " " << pow(10, counter) << "\n";
			n /= 10;
			counter++;
		}

		cout << ans << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
