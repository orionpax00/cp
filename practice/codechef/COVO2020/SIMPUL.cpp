#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> v(200007);
	int x ,h;
	for(int i = 0; i < n ; i++){
		 cin >> x >> h;
		 h += 100000;
		 v[h].push_back(x);
	}

	int q; cin >> q;
	int l, r;
	while(q--){
		cin >> l >> r >> h;
		h += 100000;
		int count = 0;
		for(int& t : v[h]){
			if(t <= r && t >= l) {count++ ; t = INT_MAX;}
		}
		cout << count << "\n";
	}
    

  return 0;
}
