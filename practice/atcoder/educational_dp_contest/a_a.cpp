#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n; cin >> n;
	vector<int> v(n); for(int& x : v) cin >> x;

	int a, b;
	a = abs(v[0] - v[1]);
	if(n <= 2) b = a;
	else 
		b = min(abs(v[0] - v[2]), a + abs(v[1] - v[2]));
	for(int i = 3; i < n; i++){
		int t = min(a + abs(v[i] - v[i-2]), b + abs(v[i] - v[i-1]));
		a = b;
		b = t;
	}

	cout << b;


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
