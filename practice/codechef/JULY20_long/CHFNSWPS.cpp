#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n ;
		map<int , int> m;
		for(int i =0 ; i < n ; i++){
			int t; cin >> t; m[t]++;
		}
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t; m[t]--;
		}
		
		int m_ = INT_MAX;
		int tobe = 0;
		bool isfound = false;
		for(auto x: m){
			if(x.second%2 != 0) {
				cout << -1 << "\n"; isfound = true; break;
			}
			else {
				m_ = min(x.first, m_);
				tobe  += abs(x.second)/2;
			}
		}
		if(!isfound){
			if(sum_ != 0){
				cout << -1 << "\n";
			}else{
				
				sort(v.begin(), v.end());
				int ans = 0;
				tobe /=2;
				for(int i = 0 ; i < v.size(); i++) {
					if( tobe > 0){
						if (tobe + 1 != m[v[i]])
							ans += v[i] * ( min(m[v[i]], tobe) + m[v[i]] / 2);
						else
							ans += v[i] * ( min(m[v[i]], tobe) + (m[v[i]] - 1)/2);
						}
					tobe -= abs(m[v[i]]);
				}
	    	cout << ans << "\n";
			}
		}
	}
  return 0;
}
