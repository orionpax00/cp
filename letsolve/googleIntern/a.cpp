#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(int N, int X, int Y, int Z, int T, vector<int> A){
	int ans = 0;
	cerr << N <<endl;
	for(int i = X - 1; i < Z; i++)
		ans ^= A[i];
	
	for(int i = Y - 1; i < T; i++)
		ans ^= A[i];

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, y, z, t; cin >> n >> x >> y >> z >> t;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	cout << solve(n, x, y, z, t, v);
    

  return 0;
}
