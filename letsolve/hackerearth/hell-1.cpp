#include <bits/stdc++.h>
using namespace std;


//Sieve of erotosthenes
template<typename T>
vector<T> sie(T n){
	vector<T> v(n+1,0);
	v[0] = 1;
	v[1] = 1;
	for(T i = 2 ; i*i <= n; i++){
		if(!v[i]){
			for(T j = i*i ; j <= n ; j+=i){
				v[j] = 1;
			}
		}
	}
	return v;
}

vector<int> primes = sie((int)1e6);

void solve(){
	int l, r; cin >> l >> r;
	int ans=0;
	for(int i = l; i <= r; i++){
		if(!primes[i]) ans++;
	}
	cout << ans << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
