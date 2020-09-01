#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string t, s; cin >> s >> t;
	

	int count_ = 0; int ans = INT_MAX;
	int n = s.length(); int m = t.length();
	for(int i = 0 ; i < n; i++){
		count_ = 0;
		for(int j = 0 ; j < m; j++){
		
			if(i+j < n && t[j] == s[i+j]) count_++;
			if(i+j == n) count_ = 0;
		}

		ans = min(ans, m - count_);
	}

	cout << ans ;
	    

  return 0;
}
