#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int t; cin >> t;
	while(t--){
		int n ; cin >> n;
		for(int i = 0 ; i < n ; i++){
			int a, b; cin >> a >> b;
		}

		if(n < 6) {cout << n << "\n"; continue;}
		else{
			int ans  = n;
			while(n > 6){
				ans += (n/3) + 1;
				n = n/3 + 1;
			}
    	cout << ans << "\n";
		}
	}

  return 0;
}
