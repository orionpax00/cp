#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin>> n;
		vector<int> v(n);
		for(auto& x : v) cin >> x;
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(v[i]&v[j] == v[i]) ans++;
			}
		}
		cout << ans <<"\n";
	}
  

  return 0;
}
