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
		int n,k;
		cin >> n >> k;
    int ans = INT_MAX; int fans = -1;
		for(int i = 0 ; i < n ; i++){
			int t ; cin >> t;
			if(k%t == 0){
				int x = k/t;
				if(x < ans){
					ans = x;
					fans = t;
				}
			}
		}
		cout << fans << "\n";
	}
  return 0;
}
