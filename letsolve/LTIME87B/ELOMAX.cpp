#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt; 
	while(tt--){
		int n; int m;
		cin >> n >> m;

		vector<int> intr(n);

		for(int& x : intr) cin >> x;

		vector<vector<int>> rat(n, vector<int>(m));
		vector<pair<int, int>> prank(n);
		vector<pair<int, int>> prat(n);

		for(int i = 0; i < n; i++){
				for(int j = 0 ; j < m; j++){
					int t; cin >> t;
					if(j == 0)rat[i][j] = intr[i] + t; 
					else rat[i][j] = rat[i][j-1] + t;
				}
		}


		for(int i = 0; i < m; i++){
			
			vector<pair<int, int>> tv(n);				
			for(int j = 0; j < n; j++){
				if(prat[j].first < rat[j][i]) prat[j] = make_pair(rat[j][i], i);
				tv[j] = {rat[j][i], j};
			}

			sort(tv.begin(), tv.end());

			int rankk = 1;
			int prev = tv[0].first;
			int counter = -1;
			while(counter < n - 1){
				if(tv[counter].first == prev){
					counter++;
				}
				else {
					rankk++;
					counter++;
					prev = tv[counter].first;
				}

				if(prank[tv[counter].second].first > rankk) prank[tv[counter].second] = {rankk, i};
			}
		}

		int ans = 0;
		for(int i = 0 ; i < n; i++){
			if(prank[i].second != prat[i].second) ans++;
		}

		cout << ans << "\n";
	}

  return 0;
}









