#include <bits/stdc++.h>
#define int long long

using namespace std;

long long bem(long long a, long long b, long long m){
	a %= m;		
	long long res=1;
  while(b>0){
    if(b&1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int MOD = 1e9 +7;



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	int n; cin >> n;

	int ans = 0;

	ans += n *(n-1);  ans %= MOD;
	if(n > 2)
		ans = (ans * (bem(10, n-2, MOD)- (n * (n-1) )/2)) % MOD;

	cout << ans;

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
