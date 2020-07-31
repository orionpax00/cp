#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t ; cin >> t;
	while(t--) {
		int n; cin >> n ; 
		int prev; cin >> prev;
		int ans = 0; 
		for(int i = 1 ; i < n ; i++){
			int t ; cin >> t;
			ans += abs(prev - t) - 1;
			prev = t;
		}
		cout << ans << "\n";
	}
    

  return 0;
}
