#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> v(n); for(int& x: v) cin >> x;	

	if(n==1){
		cout << 1 << " " << 1 << "\n";
		cout << -v[0] << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << v[0] << "\n";
		cout << 1 << " " << 1 << "\n";
		cout << -v[0] << "\n";
		return 0;
	}

	cout << 1 << " " << n - 1 << "\n";
	for(int i = 0 ; i < n - 1; i++){
		cout << v[i]*(n - 1) << " ";
	}cout << "\n";

	cout << 1 << " " << n << "\n";
	for(int i: v) cout << -i * n << " ";
	cout << "\n";

	cout << n << " " << n << "\n";
	cout << v[n-1]*(n-1) << "\n";

    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
