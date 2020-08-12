#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int k ; cin >> k;
	if(k%2 == 0 || k%5 == 0) {
		cout << -1; return 0;
	}
	if(k == 7 || k == 1) {
		cout << 1 ; return 0;
	}
	if(k % 7 ==0 ) k /= 7;
	int ans = 1;
	int res = 10;    
	int mod = 9 * k;
	while(res != 1){
		res = res*10%mod;
		ans++;
	}
	cout << ans ;

  return 0;
}
