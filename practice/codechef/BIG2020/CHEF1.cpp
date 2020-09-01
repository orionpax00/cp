#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int m, n; cin >> m >> n;	
				
		vector<vector<int> > v(10007, vector<int>());
		for(int i = 0; i < n; i++){
			int t; cin >> t; 
			v[t].push_back(i + 1);
		}
	
		vector<int> ans = {0,0};
		for(int i = 1; i < m; i++){
			if(v[i].size() != 0 && v[m - i].size() != 0){
				if(i == m - i){
						if(v[i].size() > 1) {
								ans = {v[i][0], v[i][1]};
						}
				}

				if(ans[1] == 0){
						ans = {v[i][0], v[m-i][0]};
				}
			}
		}
						
	cout << ans[0] << " " << ans[1] <<"\n";
						
	}    

  return 0;
}
