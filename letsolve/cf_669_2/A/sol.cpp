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
		int z = 0;
		int o = 0;
		for(int i = 0; i < n; i++){
			int t; cin >> t;
			if(t) o++;
			else z++;
		}
		if(n < 4){
			if(n == 2){
				if(z == 0) cout << 2 << "\n" << 1 << " " << 1 << "\n";
				else if( z == 1) cout << 1 << "\n" << 0 << "\n";
				else cout << 2 << "\n" << 0 << " " << 0 << "\n";
			}	
			if(n == 3){ 
				if(z == 0) cout << 2 << "\n" << 1 << " " << 1 << "\n";
				if(z == 1) cout << 3 << "\n" << 1 <<  " " << 1 << " " << 0 << "\n";
				if(z == 2) cout << 2 << "\n" << 0 << " " << 0 << "\n";
				if(z == 3) cout << 3 << "\n" << 0 << " " << 0 << " " << 0 << "\n";
			}	
		}	
		if(n >= 4){
			vector<int> ans;
			if(z%2 == 1){
				for(int i = 0; i < z - 1; i++) ans.push_back(0);
			}else {
				for(int i = 0; i < z; i++) ans.push_back(0);
			}

			if(o%2 == 1){
				for(int i = 0; i < o - 1; i++) ans.push_back(1);
			}else {
				for(int i = 0; i < o; i++) ans.push_back(1);
			}

			cout << ans.size() << "\n";
			for(int x : ans ) cout << x << " ";
			cout << "\n";
		}
				
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
