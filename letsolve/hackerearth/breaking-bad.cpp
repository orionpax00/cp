#include <bits/stdc++.h>
using namespace std;

int m;

void solve(){
	
	string s, c; 
	string ans;
	int coms = INT_MIN;
	for(int i = 0; i < m; i++){
		cin >> s >> c;
		int c_ = 0;
		for(char x : c)
			if(x == ',')
				c_++;

		if(c_ >= coms){
			coms = c_;
			ans = s;
		}
	}
	cout << ans << " " << coms <<"\n";	

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; 
	cin >> tt >> m;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
