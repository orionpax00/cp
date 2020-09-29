#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v(n);
		for(int& x: v) cin >> x;

		int best = 5;
		int worst = 1;

		for(int i = 0; i < n; i++){
			vector<int> binf(n);
			vector<int> winf(n);
	
			int t = 1;
			for(int j = 0; j < n; j++){
					if(v[j] < v[i] && j > i) t++;
					else if(v[j] > v[i] && j < i) t++;
			}
			best = min(best, t);
			worst = max(worst, t);
		}

	cout << best << " " << worst << "\n";
	}	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
