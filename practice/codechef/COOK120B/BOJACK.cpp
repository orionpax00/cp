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
		int ans = 0; int m_ = -1;
		for(int i = 0; i < n; i++){
			int t; cin >> t; m_ = max(m_, t);
			ans |= t;
		}   

		if(ans == m_) cout << "NO\n";
		else cout << "YES\n";
	}

  return 0;
}
