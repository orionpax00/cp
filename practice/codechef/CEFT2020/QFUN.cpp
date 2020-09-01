#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ones = 0;
		int zeros = 0;
		string s; cin >> s;
		int ans = 0;
		for(char c : s){
			if(c == '0') {ans += ones; zeros++;}
    	else { ans += zeros; ones++;}
		}
		cout << ans << "\n";
	}

  return 0;
}
