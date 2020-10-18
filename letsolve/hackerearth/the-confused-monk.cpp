#include <bits/stdc++.h>
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

int MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	int p = 1;
	int g;
	cout << n << endl;
	if(n == 1){
		int t; cin >> t;
		cout << bem(t, t, MOD) << "\n";
	}else{
		int a, b; cin >> a >> b;
		n -= 2;
		p = a*b;
		g = __gcd(a, b);

		while(n--){
			cin >> a;
			p = p*a;
			g = __gcd(g, a);
		}

		cout << bem(p, g, MOD);
	}


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
