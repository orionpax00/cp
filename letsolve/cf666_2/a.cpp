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
		vector<int> v(30);
		for(int i = 0 ; i < n ; i++){
			string t; cin >> t; 
			for(char c : t) v[c- 'a']++;
		}

		bool ok = true;
		for(int x : v){
			if(x%n) ok = false;
		}

		if(ok) cout <<"YES\n";
		else cout << "NO\n";

	}
    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
