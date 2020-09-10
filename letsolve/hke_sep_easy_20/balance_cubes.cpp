#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n ; cin >> n;
	float x = log((float)n);
	float y = log((float)3);
	float z = x/y;
//	cerr << x << "\n\n";
	int t = ceil(z);
	cout << t;	


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
