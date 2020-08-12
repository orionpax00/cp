
#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n , d;
	cin >> n >> d;
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int x, y;
		cin >> x >> y ; if( sqrt(x*x + y*y) <= d) ans++;
	}    
	cout << ans << "\n";
  return 0;
}
