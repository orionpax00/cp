#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n; vector<int> v(n); for(int& x : v) cin >> x;
		sort(v.begin(), v.end());
		
		int s = 0;
		for(int i = 0 ; i < n - 1; i++)
			s += v[i];
		
		
		if(v[n-1] > s) cout << "T\n";
		else{
			s += v[n-1];
			if(s%2) cout << "T\n";
			else cout << "HL\n";
		}
	}
			

			


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
