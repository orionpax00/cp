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
		vector<int> v(n);
		map<int, int> m;
		int ans = 0;
		for(auto &x: v) cin >> x;
		for(int i = 0; i < n ;i++){
			for(int j = i; j < n; j++){
				 m[v[i]|v[j]]++;
			}
		}
		cerr<<"\n";
		for(auto x : m){
			cerr << x.first << " : " << x.second<<"\n";
		}

		bool isfound = false;
		for(auto x: m){
			if(x.second >= 2) {
				isfound = true;		
				cout<< "No\n";
				break;
			}
		}
		if(!isfound) cout<<"YES\n";
	}

  return 0;
}
