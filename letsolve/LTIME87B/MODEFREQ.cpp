#include <bits/stdc++.h>
#define int long long

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
		if(a.first == b.first) return a.second < b.second;
		return a.first > b.first;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		map<int, int> m;
		for(int i = 0; i < n; i++){
			int tt; cin >> tt; m[tt]++;
		}



		vector<pair<int, int>> v;
		
		map <int, int> m2;

		for(auto x : m){
			m2[x.second]++;
		}

		for(auto x : m2){
			v.push_back({x.second, x.first});
		}

		sort(v.begin(), v.end(), comp);

		cout << v[0].second << "\n";
	}
    

  return 0;
}
