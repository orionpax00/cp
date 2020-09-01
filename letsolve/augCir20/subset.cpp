#include <bits/stdc++.h>
#define int long long

using namespace std;

int bin(int a, int b) {
	int ans = 1;
	while(b){
		if(b&1) a*=a;
		ans *= a;
		b >>= 1;
	}
	return ans;
}


int MAXN = 1e7 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	vector<int> v(MAXN);
	v[0] = 1;
	for(int i = 1; i < MAXN; i++) v[i] = v[i-1] + (i)*(i+1)/2 + 1;

	while(t--){
		int n ; cin >> n;
		if(n == 1) { cout << 1 << "\n" << 1 << "\n"; continue;}

		auto x = lower_bound(v.begin(), v.end(), n);
		int idx = x - v.begin();	
		if(v[idx] == n){
			int up = bin(3, idx);
			cout << idx + 1 << "\n";
			for(int i = 0; i < up; i++){
				cout << bin(3, i) << " " ;
			}
			cout << bin(3, idx) << "\n";
		}else{
			int lo = n - v[idx - 1] + 1;
			cout << lo <<"\n";
			for(int i = 0 ; i < lo; i++) cout << bin(3, i) << " ";
    	cout << "\n";
		}
	}

  return 0;
}
