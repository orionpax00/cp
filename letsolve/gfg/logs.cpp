#include <bits/stdc++.h>
using namespace std;

vector<int> v;
long long k;

bool check(long long l){
	long long c = 0;
	for(int x : v){
		if(x%l == 0) c += (x/l) - 1;
		else c += (x/l);
	}
	return c <= k;
}

void solve(){
	int n ; cin >> n >> k;
	v.resize(n);
	for(int& x: v) cin >> x;
	long long ans;
	long long l = 1;
	long long h = 1e17;
	while(l <= h){
		long long mid = (l+h)/2;
		if(check(mid)){
			ans = mid;
			h = mid - 1;
		}else{
			l = mid+1;
		}
	}
	cout << ans ;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
