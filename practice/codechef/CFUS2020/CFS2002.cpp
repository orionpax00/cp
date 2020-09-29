#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt; cin >> tt;
	while(tt--){
		map<int, vector<int>> m;
		int n; cin >> n;
		vector<int> v(n);
		vector<int> pref(n + 1);
		vector<int> e(n+1);
		vector<int> o(n+1);
		for(int i = 0; i < n; i++){
			int t; cin >> t; v[i] = t; pref[i+1] = pref[i] + t;
			m[t].push_back(i);

			if(t&1){ o[i+1] = o[i] + 1; e[i+1] = e[i];}
			else{ e[i+1] = e[i] +1; o[i+1] = o[i];};

		}
		int ans = 0;	
		vector<int> isvisited(n);

		map<int, int> visit;
		for(auto x : m){
			int prev = INT_MAX;
			if(visit.count(v[x.second[0]])) continue;
			for(int j = 1; j < (int)x.second.size(); j++){
				if(x.second[j] - x.second[j - 1] < prev){
					prev = x.second[j] - x.second[j - 1];  
					if(v[x.second[j-1]]%2 == 0){
						if((e[x.second[j]] - e[x.second[j-1] + 1])%2 == 0)
							ans = max(ans, pref[x.second[j]] - pref[x.second[j - 1] + 1]);
					}else{
						if((o[x.second[j]] - o[x.second[j-1] + 1])%2)
							ans = max(ans, pref[x.second[j]] - pref[x.second[j - 1] + 1]);
					}
				}
			}
			visit[v[x.second[0]]]++;
		}	

		cout << ans << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
