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
		string s; int n;
		cin >> n >> s;

		map<char, int> m;
		for(char c : s) m[c]++;
		bool flag = true;
		for(auto x :  m)
			if(x.second&1) flag = false;
    if(flag) cout << "YES\n";
		else cout << "NO\n";
	}

  return 0;
}
