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
		bool eq = false;
		int total_sum = ( n * (n + 1) ) / 2;
		if(total_sum % 2 ) {
			cout << 0 << "\n";
			continue;
		}else{
			//implement binary search, linear search gave tle
			int m;
			int l = 1, r = n;
			while(l <= r){
				int mid = (l+r)/2;
				int mid1 = mid+1;
				int sum = total_sum - (mid * ( mid + 1) ) / 2 + mid;
				int sum2 = total_sum - (mid1 *( mid1 + 1) ) /2 + mid1;
				if(sum == total_sum/2) { eq = true; m = mid; break;}
				if( sum > total_sum/2 && sum2 < total_sum/2){ m = mid; break;}
				else if ( sum < total_sum/2) r = mid - 1;
				else l = mid + 1;
			}


			if(eq){
				m--;
				int ans = (m * (m - 1))/2 + (( n - m ) * ( n - m - 1))/2 + n - m;
				cout << ans << "\n";
			}
			else
				cout << n - m + 1<< "\n";
		}
	}
		

			


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
