#include <bits/stdc++.h>
using namespace std;

int MOD = 1e6+3;

vector<long long> fac(MOD + 1);
void fact(){
	fac[0] = 1;
	for(long long i = 0; i < MOD; i++){
		fac[i+1] = (fac[i]*(i+1))%MOD;
	}
}

void solve(){
	long n, x; cin >> n >> x;
//	long long ans = x;
	if(n >= MOD){ cout << 0 << "\n"; return;}

	cout << (x * fac[n])%MOD << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	fact();
	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
