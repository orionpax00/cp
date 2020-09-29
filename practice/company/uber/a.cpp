#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& v, int x){
	return upper_bound(v.begin(), v.end(), x) -  lower_bound(v.begin(), v.end(), x);
}


int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int& x : v) cin >> x;
	int tt; cin >> tt;
	while(tt--){
		int t; cin >> t;
		cout << solve(v, t) << "\n";
	}


	return 0;
}
