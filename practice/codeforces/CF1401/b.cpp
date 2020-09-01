#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; 
	while(t--){
		int x1, y1, z1, x2, y2, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int ans = 0;
		ans += 2 * min(z1, y2);
		ans -= 2 * max(0, z2 - x1 - (z1 - min(y2, z1)));
		cout << ans << "\n";
	}    
    

  return 0;
}
