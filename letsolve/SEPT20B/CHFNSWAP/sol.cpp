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
		int total_sum = ( n * (n + 1) ) / 2;
		if(total_sum % 2 ) {
			cout << 0 << "\n";
			continue;
		}else{
			//implement binary search, linear search gave tle
			int m;
			for(int i = n; i >= n/2; i--){
				int sum = total_sum - (i * ( i + 1) ) / 2 + i;
				if( sum > total_sum/2){ m = i; break;}
			}

			cout << n - m + 1<< "\n";
		}
	}
		

			


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
