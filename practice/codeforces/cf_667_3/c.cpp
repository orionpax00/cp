#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n, x, y; cin >> n >> x >> y;
		
		auto ok = [&](int f , int d){
			bool hasx = false; bool hasy = false;
			for(int i = 0; i < n; i++){
				if(f + i*d == x) hasx = true;
				if(f + i*d == y) hasy = true;
			}
			return hasx && hasy;
		};

		int max_ = LLONG_MAX;
		int st = 1; int diff = 1;
		for(int i = 1; i <= x; i++){
			for(int j = 1; j <= y - x; j++){
				if(i + (n - 1)*j < y) continue;
				if(i + (n-1)*j < max_){
					if(ok(i, j)){
						max_ = i + (n-1)*j;
						diff = j;
						st = i;
					}
				}
			}
		}

		for(int i = 0; i < n ; i++) cout << (st + i * diff) << " ";
		cout << "\n";
	}	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
