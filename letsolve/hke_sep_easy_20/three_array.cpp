#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k ; cin >> n >> m >> k;
	
	vector<int> a(n), b(n), c(n);

	for(int i = 0 ; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	int l1, l2 , l3 ,r1 , r2, r3;
	cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;	
	for(int i = l1; i <= r1; i++){
		for(int j = l2; j <= r2; j++){
			for(int k = l3; k <= r3; k++){
				int counter = 0;
				for(int t = 0 ; t < n; t++){
					if(abs(i * a[t] + j * b[t] - k * c[t])%m == 0) counter++;
				}
				if(counter == k) {
					cout << i << " " << j << " " << k;
					return 0;
				}
			}
		}
	}
	cout << -1 ;

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
