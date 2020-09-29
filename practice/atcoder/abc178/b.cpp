#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int ans = LLONG_MIN;
	int a, b , c, d; cin >> a >> b >> c >> d;

	vector<int> v = {a, b, c, d};

	for(int i = 0 ; i < 2; i++){
		for( int j = 2; j < 4; j++){
			if( i == j) continue;
			else{
				ans = max(ans, v[i]*v[j]);
			}
		}
	}

	cout << ans;
   


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
