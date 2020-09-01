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
		int n, q; cin >> n >> q;
		vector<int> v(n+1, 0);
	 	for(int i = 0 ; i < q; i++){
				int l, r, V; cin >> l >> r >> V;
				v[l] += V;
				v[r+1] -= V;
		}

		for(int i  = 1; i <= n; i++){
				v[i] += v[i-1];
		}

		int s_ = 0;
		for(int i = 0; i < n; i++) s_ += v[i];

		cout << s_ <<"\n";
	}
    

  return 0;
}
