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
		string s; cin >> s;
		char c = s[n-1];
		string ans = "";
		for(int i = 0 ; i < n; i++) ans += c;
		cout << ans << "\n";
	}    

  return 0;
}
