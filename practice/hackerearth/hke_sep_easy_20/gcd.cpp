#include <bits/stdc++.h>
#define int long long


using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; int q; cin >> n >> q;
	
	vector<int> v(n);
	for(int& x: v) cin >> x;	
	
	while(q--){

		int t;	cin >> t;
		if(t == 1 || t == 2){
			int l, r, x; cin >> l >> r >> x;
			
			if(t == 1){
				for(int i = l-1; i < r; i++){
					v[i] = x;
				}
			}


			if(t == 2){
				for(int i = l-1; i < r; i++){
					v[i] = __gcd(x, v[i]);
				}
			}
		}else{
			int l , r; cin >> l >> r;
			if(t == 3){	
				cout << *max_element(v.begin() + l - 1, v.begin() + r) << "\n";
			}
			if(t == 4){

				int sum_ = 0;
				for(int i = l - 1; i < r; i++) sum_ += v[i];
				cout << sum_ << "\n";
			}	
		}


	}
	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
