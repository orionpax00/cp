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
		string s; cin >> s;
		
		map<char, int> m;
		for(char c : s) m[c]++;

		cout << 2 * (min(m['U'], m['D']) + min(m['L'], m['R'])) << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
