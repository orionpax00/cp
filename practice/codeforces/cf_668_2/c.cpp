#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int tt; cin >> tt;
	while(tt--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		bool ok = true;
		for(int i = 0; i < n - k; i+=){
			if(s[i] != s[i+k]) ok = false;
		}

		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
