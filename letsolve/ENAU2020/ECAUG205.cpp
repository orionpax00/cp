#include <bits/stdc++.h>
#define int long long

using namespace std;


vector<int> v;
int n;
int max_ = INT_MIN;
int k;

bool distributable(int m){
	int count = 0;
	for(int i = 0; i < n; i++) count += v[i]/m;
	if(count >= k) return true;
	return false;
}

int solve(){
	int low = 1, high = max_;
	int res;
	while(low <= high){
		int mid = (high+low)/2;
		if(distributable(mid)){
			res = mid; low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return res;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		cin >> n >> k;
		v.resize(n);
		
		for(int i = 0 ; i < n; i++){
			int t; cin >> t;
			v[i] = t;
			max_ = max(max_, t);
		}
		
		cout << solve() << "\n";

	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
